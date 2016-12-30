#pragma once
#ifndef __StackLayout_h__
#define __StackLayout_h__

#include "qstackedlayout.h"

class StackLayout :public QStackedLayout
{
	Q_OBJECT
public:
	StackLayout(QWidget *parent = nullptr);
	~StackLayout();

	QSize sizeHint();
	QSize minimumSize();
	QSize maximumSize();

	void setGeometry(QRect& rect);

private:
	QSize fixSizePolicy(QSize& size, QSize& hint, QSizePolicy& policy);

public Q_SLOTS:
	void _onCurrentChanged(int index);

private:

};

#endif