#pragma once

#ifndef __NOFOCUSDELEGATE_H__
#define __NOFOCUSDELEGATE_H__

#include <QStyledItemDelegate>
class NoFocusDelegate : public QStyledItemDelegate 
{
	Q_OBJECT
public:
	explicit NoFocusDelegate(QObject* parent = Q_NULLPTR);
	~NoFocusDelegate();
	void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const Q_DECL_OVERRIDE;
};

#endif