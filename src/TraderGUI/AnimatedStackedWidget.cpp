#include "StackLayout.h"
#include "CrossFadePixmapWidget.h"
#include "AnimatedStackedWidget.h"
#include "QPropertyAnimation"


AnimatedStackedWidget::AnimatedStackedWidget(QWidget* parent, bool animationEnabled) :QFrame(parent)
{
	__animationEnabled = animationEnabled;

	layout = new StackLayout(this);

	__fadeWidget = new CrossFadePixmapWidget(this);

	transitionAnimation = new QPropertyAnimation(__fadeWidget, "blendingFactor_", this);
	transitionAnimation->setStartValue(0.0);
	transitionAnimation->setEndValue(1.0);
	if (animationEnabled)
	{
		transitionAnimation->setDuration(100);
	}
	else
	{
		transitionAnimation->setDuration(0);
	}
	QObject::connect(transitionAnimation, &QPropertyAnimation::finished, this, &AnimatedStackedWidget::__onTransitionFinished);
	
	layout->addWidget(__fadeWidget);
	QObject::connect(layout, &StackLayout::currentChanged, this, &AnimatedStackedWidget::__onLayoutCurrentChanged);

	setLayout(layout);
}
AnimatedStackedWidget::~AnimatedStackedWidget()
{
	delete transitionAnimation;
	delete __fadeWidget;
	delete layout;
}

void AnimatedStackedWidget::setAnimationEnabled(bool animationEnabled)
{
	if (__animationEnabled != animationEnabled)
	{
		__animationEnabled = animationEnabled;

		if (animationEnabled)
		{
			transitionAnimation->setDuration(100);
		}
		else
		{
			transitionAnimation->setDuration(0);
		}
	}
}
bool AnimatedStackedWidget::animationEnabled()
{
	return __animationEnabled;
}

int AnimatedStackedWidget::addWidget(QWidget* w)
{
	return insertWidget(layout->count(), w);
}
int AnimatedStackedWidget::insertWidget(int index, QWidget* w)
{
	index = index <= count() ? index : count();

	__widgets.insert(index, w);
	if (index <= __currentIndex || __currentIndex == -1)
	{
		__currentIndex += 1;
	}

	return layout->insertWidget(index, w);
}
void AnimatedStackedWidget::removeWidget(QWidget* w)
{
	int index = __widgets.indexOf(w);
	layout->removeWidget(w);
	__widgets.remove(index);
}
QWidget* AnimatedStackedWidget::widget(int index)
{
	return __widgets[index];
}
int AnimatedStackedWidget::indexOf(QWidget* w)
{
	return __widgets.indexOf(w);
}

int AnimatedStackedWidget::count()
{
	return layout->count() - 1 <= 0 ? 0 : layout->count() - 1;
}

void AnimatedStackedWidget::setCurrentWidget(QWidget* w)
{
	int index = __widgets.indexOf(w);
	setCurrentIndex(index);
}
void AnimatedStackedWidget::setCurrentIndex(int index)
{
	int temp = index <= count() - 1 ? index : count() - 1;
	index = temp <= 0 ? 0 : temp;
	if (__currentIndex == -1)
	{
		layout->setCurrentIndex(index);
		__currentIndex = index;
		return;
	}
	
	QWidget* current = __widgets[__currentIndex];
	QWidget* next_widget = __widgets[index];

	QPixmap current_pix, next_pix;
	current_pix = QPixmap::grabWidget(current);
	next_pix = QPixmap::grabWidget(next_widget);

	/*if (!has_pending_resize(current))
	{
		current_pix = current->grab();
	}
			
	if (!has_pending_resize(next_widget))
	{
		next_pix = next_widget->grab();
	}*/
	
	bool old_state = updatesEnabled();
	setUpdatesEnabled(false);
	if (old_state)
	{
		__fadeWidget->setPixmap(&current_pix);
		__fadeWidget->setPixmap2(&next_pix);
		__nextCurrentIndex = index;
		__transitionStart();
	}
	setUpdatesEnabled(old_state);
}
int AnimatedStackedWidget::currentIndex()
{
	return __currentIndex;
}

QSize AnimatedStackedWidget::sizeHint()
{
	//QSize hint = QFrame::sizeHint();
	QSize hint = layout->sizeHint();
	if(hint.isEmpty())
	{
		hint = QSize(0, 0);
	}
	return hint;
}

void AnimatedStackedWidget::__transitionStart()
{
	__fadeWidget->blendingFactor_ =  0.0;
	layout->setCurrentWidget(__fadeWidget);
	transitionAnimation->start();
	emit transitionStarted();
}
void AnimatedStackedWidget::__onTransitionFinished()
{
	__fadeWidget->blendingFactor_ = 1.0;
	__currentIndex = __nextCurrentIndex;

	bool old_state = updatesEnabled();
	setUpdatesEnabled(false);
	if (old_state)
	{
		layout->setCurrentIndex(__currentIndex);
	}
	setUpdatesEnabled(old_state);
		
	emit transitionFinished();
}
void AnimatedStackedWidget::__onLayoutCurrentChanged(int index)
{
	if (index != count())
		emit currentChanged(index);
}

bool AnimatedStackedWidget::has_pending_resize(QWidget* w)
{
	return w->testAttribute(Qt::WA_PendingResizeEvent) || !w->testAttribute(Qt::WA_WState_Created);
}