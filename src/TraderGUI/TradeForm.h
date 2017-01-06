#pragma once
#ifndef __TRADEFORM_H__
#define __TRADEFORM_H__

#include <QWidget>
#include <qtablewidget.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class TradeForm;
}

namespace cktrader {
	class ServiceMgr;
}

class TradeForm :public QWidget
{
	Q_OBJECT

public:
	TradeForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent = 0);
	~TradeForm();

	void init();
	
	void onTrade(Datablk& tr);

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:
	void updateContent(TradeData trade);

signals:
	void updateEvent(TradeData trade);

private:
	Ui::TradeForm* ui;
	QStringList table_col_;
	QMap<QString, int> table_row_;

	cktrader::ServiceMgr* serviceMgr;

	QTextCodec * codec;
};

#endif