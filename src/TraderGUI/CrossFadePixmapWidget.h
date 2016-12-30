#pragma once
#ifndef __CrossFadePixmapWidget_H_
#define __CrossFadePixmapWidget_H_

#include "qwidget.h"

class CrossFadePixmapWidget:public QWidget
{
	Q_OBJECT
	Q_PROPERTY(float blendingFactor_ READ blendingFactor WRITE setBlendingFactor)
public:
	CrossFadePixmapWidget(QWidget* parent = nullptr, QPixmap* pixmap1 = nullptr, QPixmap* pixmap2 = nullptr);
	~CrossFadePixmapWidget();

	void setPixmap(QPixmap* pixmap);
	void setPixmap2(QPixmap* pixmap);

	void setBlendingFactor(float factor);
	float blendingFactor();

	QSize sizeHint();

	float blendingFactor_;

protected:
	void paintEvent(QPaintEvent *event);

private:	
	QPixmap pixmap1;
	QPixmap pixmap2;
};

#endif