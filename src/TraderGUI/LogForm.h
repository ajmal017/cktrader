#pragma once
#ifndef __LOGFORM_H__
#define __LOGFORM_H__

#include <QWidget>
#include <qtablewidget.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class LogForm;
}

namespace cktrader {
	class ServiceMgr;
}

class LogForm :public QWidget
{
	Q_OBJECT

public:
	LogForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent = 0);
	~LogForm();

	void init();

	void onLog(Datablk& log);

private:
	void adjustTableWidget(QTableWidget* tableWidget);


private:
	Ui::LogForm* ui;
	QStringList table_col_;

	cktrader::ServiceMgr* serviceMgr;

	QTextCodec * codec;
};

#endif