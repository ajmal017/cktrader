#pragma once
#ifndef __ORDERFORM_H__
#define __ORDERFORM_H__

#include <QWidget>
#include <qtablewidget.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class OrderForm;
}

namespace cktrader {
	class ServiceMgr;
}

class OrderForm :public QWidget
{
	Q_OBJECT

public:
	OrderForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent = 0);
	~OrderForm();

	void init();

	void onOrder(Datablk& or);

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:
	void updateContent(OrderData order);
	void cancel_tableWidget_doubleCellClicked(int row, int column);

signals:
	void updateEvent(OrderData order);

private:
	Ui::OrderForm* ui;
	QStringList table_col_;
	QMap<QString, int> table_row_;

	cktrader::ServiceMgr* serviceMgr;

	QTextCodec * codec;
};

#endif