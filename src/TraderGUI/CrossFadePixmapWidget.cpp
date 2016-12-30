#include "CrossFadePixmapWidget.h"
#include "qpainter.h"
#include <QPaintEvent>

CrossFadePixmapWidget::CrossFadePixmapWidget(QWidget* parent, QPixmap* pixmap1, QPixmap* pixmap2)
	:QWidget(parent)
	, pixmap1()
	, pixmap2()
{
	if (pixmap1&&pixmap2)
	{
		setPixmap(pixmap1);
		setPixmap2(pixmap2);
	}
	
	blendingFactor_ = 0.0;
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
CrossFadePixmapWidget::~CrossFadePixmapWidget()
{

}

void CrossFadePixmapWidget::setPixmap(QPixmap* pixmap)
{
	if (pixmap)
	{
		pixmap1 = *pixmap;
	}
	
	updateGeometry();
}
void CrossFadePixmapWidget::setPixmap2(QPixmap* pixmap)
{
	if (pixmap)
	{
		pixmap2 = *pixmap;
	}
	
	updateGeometry();
}

void CrossFadePixmapWidget::setBlendingFactor(float factor)
{
	blendingFactor_ = factor;
	updateGeometry();
	repaint();
}

float CrossFadePixmapWidget::blendingFactor()
{
	return blendingFactor_;
}

QSize CrossFadePixmapWidget::sizeHint()
{
	if (!pixmap1.isNull() && !pixmap2.isNull())
	{
		QSize size1 = pixmap1.size();
		QSize size2 = pixmap2.size();
		return size1 + blendingFactor_ * (size2 - size1);
	}		
	else
	{
		return QWidget::sizeHint();
	}	
}
void CrossFadePixmapWidget::paintEvent(QPaintEvent *event)
{
	QPainter* p = new QPainter(this);
	p->setClipRect(event->rect());
	float factor = blendingFactor_ * blendingFactor_;
	if (!pixmap1.isNull() && (1. - factor))
	{
		p->setOpacity(1. - factor);
		p->drawPixmap(QPoint(0, 0), pixmap1);
	}
	if (!pixmap2.isNull() && factor)
	{
		p->setOpacity(factor);
		p->drawPixmap(QPoint(0, 0), pixmap2);
	}

	delete p;
	p = nullptr;
}