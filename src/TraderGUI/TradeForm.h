#pragma once
#ifndef __TRADEFORM_H__
#define __TRADEFORM_H__

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
	class TradeForm;
}

class TradeForm :public QWidget
{
	Q_OBJECT

public:
	TradeForm(QWidget* parent = 0);
	~TradeForm();

	void init();
	void shutdown();

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:

private:
	Ui::TradeForm* ui;
	QStringList table_col_;
};

#endif