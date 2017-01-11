#pragma once
#ifndef __CONTRACTFORM_H__
#define __CONTRACTFORM_H__

#include <QWidget>
#include <qtablewidget.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class ContractForm;
}

namespace cktrader {
	class ServiceMgr;
}

class ContractForm :public QWidget
{
	Q_OBJECT

public:
	ContractForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent = 0);
	~ContractForm();

	void init();

	void onContract(Datablk& contract);

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:
	void updateContent(ContractData contract);
	void cancel_tableWidget_doubleCellClicked(int row, int column);

signals:
	void updateEvent(ContractData contract);

private:
	Ui::ContractForm* ui;
	QStringList table_col_;
	QMap<QString, int> table_row_;

	cktrader::ServiceMgr* serviceMgr;

	QTextCodec * codec;
};

#endif