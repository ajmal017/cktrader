#pragma once
#ifndef __AnimatedStackedWidget_h_
#define __AnimatedStackedWidget_h_
#include "qframe.h"

class StackLayout;
class CrossFadePixmapWidget;
class QPropertyAnimation;

class AnimatedStackedWidget :public QFrame
{
	Q_OBJECT
public:
	AnimatedStackedWidget(QWidget* parent = Q_NULLPTR, bool animationEnabled = true);
	~AnimatedStackedWidget();

	void setAnimationEnabled(bool animationEnabled);
	bool animationEnabled();

	int addWidget(QWidget* w);
	int insertWidget(int index, QWidget* w);
	void removeWidget(QWidget* w);
	QWidget* widget(int index);
	int indexOf(QWidget* w);

	int count();

	void setCurrentWidget(QWidget* w);
	void setCurrentIndex(int index);
	int currentIndex();

	QSize sizeHint();

	void __transitionStart();

public Q_SLOTS:	
	void __onTransitionFinished();
	void __onLayoutCurrentChanged(int index);

Q_SIGNALS :
	void transitionStarted();
	void currentChanged(int x);
	void transitionFinished();

private:
	bool has_pending_resize(QWidget* w);

private:
	bool __animationEnabled;

	StackLayout* layout;
	CrossFadePixmapWidget *__fadeWidget;
	QPropertyAnimation* transitionAnimation;

	QVector<QWidget*> __widgets;
	int __currentIndex = -1;
	int __nextCurrentIndex = -1;
};

#endif