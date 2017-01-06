#pragma once
#ifndef __ACCOUNTFORM_H__
#define __ACCOUNTFORM_H__

#include <QWidget>
#include <qtablewidget.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class AccountForm;
}

namespace cktrader {
	class ServiceMgr;
}

class AccountForm :public QWidget
{
	Q_OBJECT

public:
	AccountForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent = 0);
	~AccountForm();

	void init();

	void onAccount(Datablk& account);

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:
	void updateContent(AccountData ac);

signals:
	void updateEvent(AccountData er);

private:
	Ui::AccountForm* ui;
	QStringList table_col_;
	QMap<QString, int> table_row_;

	cktrader::ServiceMgr* serviceMgr;

	QTextCodec * codec;
};

#endif