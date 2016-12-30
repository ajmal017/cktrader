#include "StackLayout.h"
#include "qwidget.h"

StackLayout::StackLayout(QWidget *parent) :QStackedLayout(parent)
{
	QObject::connect(this,&QStackedLayout::currentChanged,this,&StackLayout::_onCurrentChanged);
}
StackLayout::~StackLayout()
{

}

QSize StackLayout::sizeHint()
{
	QWidget* current = currentWidget();
	if (current)
	{
		QSize hint = current->sizeHint();
		// Clip the hint with min / max sizes.
		return hint.expandedTo(current->minimumSize()).boundedTo(current->maximumSize());
	}
	else
	{
		return QStackedLayout::sizeHint();
	}
}
QSize StackLayout::minimumSize()
{
	QWidget* current = currentWidget();
	if (current)
	{
		return current->minimumSize();
	}
	else
	{
		return QStackedLayout::minimumSize();
	}
}
	
QSize StackLayout::maximumSize()
{
	QWidget* current = currentWidget();
	if (current)
	{
		return current->maximumSize();
	}
	else
	{
		return QStackedLayout::maximumSize();
	}
}

void StackLayout::setGeometry(QRect& rect)
{
	QStackedLayout::setGeometry(rect);
	for (int i = 0; i <= count(); i++)
	{
		QWidget* w = widget(i);
		QSize hint = w->sizeHint();
		QRect geom = QRect(rect);
		QSize size = rect.size().expandedTo(w->minimumSize()).boundedTo(w->maximumSize());
		size = fixSizePolicy(size, hint, w->sizePolicy());
		geom.setSize(size);
		if (geom != w->geometry())
		{
			w->setGeometry(geom);
		}				
	}			
}

void StackLayout::_onCurrentChanged(int index)
{
	invalidate();
}

QSize StackLayout::fixSizePolicy(QSize& size, QSize& hint, QSizePolicy& policy)
{
	int width = hint.width();
	int height = hint.height();
	Qt::Orientations expanding = policy.expandingDirections();
	QSizePolicy::Policy hpolicy = policy.horizontalPolicy();
	QSizePolicy::Policy vpolicy = policy.verticalPolicy();

	if (expanding & Qt::Horizontal)
	{
		width = width>=size.width()? width: size.width();
	}
	
	if (hpolicy == QSizePolicy::Maximum)
	{
		width = width <= size.width() ? width : size.width();
	}
			
	if (expanding & Qt::Vertical)
	{
		height = height>=size.height()? height: size.height();
	}
				
	if (vpolicy == QSizePolicy::Maximum)
	{
		height = height<=hint.height()? height: hint.height();
	}		

	return QSize(width, height).boundedTo(size);
}