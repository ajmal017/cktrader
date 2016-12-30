#pragma once
#ifndef __CollapsibleDockWidget_h_
#define __CollapsibleDockWidget_h_

#include "qdockwidget.h"


/*
*This :class:`QDockWidget` subclass overrides the `close` header
*button to instead collapse to a smaller size. The contents contents
*to show when in each state can be set using the ``setExpandedWidget``
*and ``setCollapsedWidget``.

*note:: Do  not use the base class ``QDockWidget.setWidget`` method
*to set the docks contents. Use set[Expanded|Collapsed]Widget
*instead.
*/
class QAbstractButton;
class AnimatedStackedWidget;

class CollapsibleDockWidget:public QDockWidget
{
	Q_OBJECT
public:
	CollapsibleDockWidget(QWidget* parent = nullptr);
	~CollapsibleDockWidget();

	void setExpanded(bool state);
	bool expanded();

	void setWidget(QWidget* widget);
	void setExpandedWidget(QWidget* widget);
	QWidget* expandedWidget();
	void setCollapsedWidget(QWidget* widget);
	QWidget* collapsedWidget();

	void setAnimationEnabled(bool animationEnabled);

	bool animationEnabled();

	QWidget* currentWidget();

	void expand();

	void collapse();

	bool eventFilter(QObject *watched, QEvent *e);

	bool event(QEvent *event);

private:
	void __fixIcon();
	void __fixMinimumWidth();
	bool __hasFixedWidth();

Q_SIGNALS:
	void expandedChanged(bool s);

public slots:
	void __onFeaturesChanged(QDockWidget::DockWidgetFeatures features);
	void __onDockLocationChanged(Qt::DockWidgetArea area);
	void __onTransitionStarted();
	void __onTransitionFinished();

private:
	bool __expanded = true;

	QWidget* __expandedWidget = nullptr;
	QWidget* __collapsedWidget = nullptr;

	int __trueMinimumWidth = -1;

	QIcon* __iconRight = nullptr;
	QIcon* __iconLeft = nullptr;

	QAbstractButton* __closeButton;

	AnimatedStackedWidget* __stack;
};
#endif