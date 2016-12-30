#pragma once
#ifndef __ORDERFORM_H__
#define __ORDERFORM_H__

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
	class OrderForm;
}

class OrderForm :public QWidget
{
	Q_OBJECT

public:
	OrderForm(QWidget* parent = 0);
	~OrderForm();

	void init();
	void shutdown();

private:
	void adjustTableWidget(QTableWidget* tableWidget);

	private slots:

private:
	Ui::OrderForm* ui;
	QStringList table_col_;
};

#endif