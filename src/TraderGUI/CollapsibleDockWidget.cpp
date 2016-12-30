
#include "CollapsibleDockWidget.h"
#include <QPixmap> 
#include <QStyle>
#include <QEvent>
#include <QAbstractButton>
#include "AnimatedStackedWidget.h"

CollapsibleDockWidget::CollapsibleDockWidget(QWidget* parent):QDockWidget(parent)
{
	setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable);

	setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

	QObject::connect(this,&QDockWidget::featuresChanged,this, &CollapsibleDockWidget::__onFeaturesChanged);
	QObject::connect(this, &QDockWidget::dockLocationChanged, this, &CollapsibleDockWidget::__onDockLocationChanged);

	//Use the toolbar horizontal extension button icon as the default
	// for the expand / collapse button
	QPixmap pm = style()->standardPixmap(QStyle::SP_ToolBarHorizontalExtensionButton);

	// Rotate the icon
	QTransform transform;
	transform.rotate(180);

	QPixmap pm_rev = pm.transformed(transform);

	__iconRight = new QIcon(pm);
	__iconLeft = new QIcon(pm_rev);

	__closeButton = findChild<QAbstractButton*>("qt_dockwidget_closebutton");
	__closeButton->installEventFilter(this);

	__stack = new AnimatedStackedWidget(this);
	__stack->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	QObject::connect(__stack, &AnimatedStackedWidget::transitionStarted, this, &CollapsibleDockWidget::__onTransitionStarted);
	QObject::connect(__stack, &AnimatedStackedWidget::transitionFinished, this, &CollapsibleDockWidget::__onTransitionFinished);


	QDockWidget::setWidget(__stack);

	__closeButton->setIcon(*__iconLeft);
}
CollapsibleDockWidget::~CollapsibleDockWidget()
{
	delete __stack;
	delete __iconRight;
	delete __iconLeft;

}

void CollapsibleDockWidget::setExpanded(bool state)
{
	if (__expanded != state)
	{
		__expanded = state;
		if (state && __expandedWidget)
		{
			__stack->setCurrentWidget(__expandedWidget);
		}
		else if (!state && __collapsedWidget)
		{
			__stack->setCurrentWidget(__collapsedWidget);
		}	
		__fixIcon();

		emit expandedChanged(state);
	}	
}
bool CollapsibleDockWidget::expanded()
{
	return __expanded;
}

void CollapsibleDockWidget::setWidget(QWidget* widget)
{
	throw std::runtime_error("Please use the 'setExpandedWidget'/'setCollapsedWidget' "
						"methods to set the contents of the dock widget.");
}
void CollapsibleDockWidget::setExpandedWidget(QWidget* widget)
{
	if (widget == __expandedWidget)
	{
		return;
	}
	
	if (__expandedWidget)
	{
		__stack->removeWidget(__expandedWidget);
	}

	__stack->insertWidget(0, widget);
	__expandedWidget = widget;

	if (__expanded)
	{
		__stack->setCurrentWidget(widget);
		updateGeometry();
	}
}
QWidget* CollapsibleDockWidget::expandedWidget()
{
	return __expandedWidget;
}
void CollapsibleDockWidget::setCollapsedWidget(QWidget* widget)
{
	if (widget == __collapsedWidget)
	{
		return;
	}
	if (__collapsedWidget)
	{
		__stack->removeWidget(__collapsedWidget);
	}

	__stack->insertWidget(1, widget);
	__collapsedWidget = widget;

	if (!__expanded)
	{
		__stack->setCurrentWidget(widget);
		updateGeometry();
	}
}

QWidget* CollapsibleDockWidget::collapsedWidget()
{
	return __collapsedWidget;
}

void CollapsibleDockWidget::setAnimationEnabled(bool animationEnabled)
{
	__stack->setAnimationEnabled(animationEnabled);
}

bool CollapsibleDockWidget::animationEnabled()
{
	return __stack->animationEnabled();
}

QWidget* CollapsibleDockWidget::currentWidget()
{
	if (__expanded)
		return __expandedWidget;
	else
		return __collapsedWidget;
}

void CollapsibleDockWidget::expand()
{
	setExpanded(true);
}

void CollapsibleDockWidget::collapse()
{
	setExpanded(false);
}

bool CollapsibleDockWidget::eventFilter(QObject *obj, QEvent *e)
{
	if (obj == __closeButton)
	{
		QEvent::Type etype = e->type();
		if (etype == QEvent::MouseButtonPress)
		{
			setExpanded(!__expanded);
			return true;
		}
		else if (etype == QEvent::MouseButtonDblClick || etype == QEvent::MouseButtonRelease)
		{
			return true;
		}
		
	}
		
	//TODO : which other events can trigger the button(is the button focusable).
	return QDockWidget::eventFilter(obj, e);
}

bool CollapsibleDockWidget::event(QEvent *event)
{
	if (event->type() == QEvent::LayoutRequest)
	{
		__fixMinimumWidth();
	}

	return QDockWidget::event(event);
}

void CollapsibleDockWidget::__onFeaturesChanged(QDockWidget::DockWidgetFeatures features)
{
	
}

void CollapsibleDockWidget::__onDockLocationChanged(Qt::DockWidgetArea area)
{
	if (area == Qt::LeftDockWidgetArea)
	{
		setLayoutDirection(Qt::LeftToRight);
	}
	else
	{
		setLayoutDirection(Qt::RightToLeft);
	}
	__stack->setLayoutDirection(parentWidget()->layoutDirection());
	__fixIcon();
}

void CollapsibleDockWidget::__onTransitionStarted()
{

}
void CollapsibleDockWidget::__onTransitionFinished()
{

}

void CollapsibleDockWidget::__fixIcon()
{
	Qt::LayoutDirection direction = layoutDirection();

	QIcon* icon;
	if (direction == Qt::LeftToRight)
	{
		if (__expanded)
		{
			icon = __iconLeft;
		}		
		else
		{
			icon = __iconRight;
		}		
	}	
	else
	{
		if (__expanded)
		{
			icon = __iconRight;
		}		
		else
		{
			icon = __iconLeft;
		}	
	}
	__closeButton->setIcon(*icon);
}

void CollapsibleDockWidget::__fixMinimumWidth()
{
	QSize size = __stack->sizeHint();
	int left,top,right,bottom;
	int width;
	if (size.isValid() && !size.isEmpty())
	{
		getContentsMargins(&left, &top, &right, &bottom);
		width = size.width() + left + right;

		if (width < minimumSizeHint().width())
		{
			if (!__hasFixedWidth())
			{
				__trueMinimumWidth = minimumSizeHint().width();
			}
		}
		else
		{
			if (__hasFixedWidth())
			{
				if (width >= __trueMinimumWidth)
				{
					// Unset the fixed size.

					__trueMinimumWidth = -1;
					setFixedWidth(QWIDGETSIZE_MAX);
					updateGeometry();
				}
				else
				{
					setFixedWidth(width);
				}
			}

		}
	}
}

bool CollapsibleDockWidget::__hasFixedWidth()
{
	return __trueMinimumWidth >= 0;
}