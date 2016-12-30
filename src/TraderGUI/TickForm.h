#pragma once
#ifndef __TICKFORM_H__
#define __TICKFORM_H__

#include <QWidget>
#include <qtablewidget.h>
#include <qmap.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class TickForm;
}

/*namespace cktrader {
	class ServiceMgr;
}*/


class TickForm:public QWidget
{
	Q_OBJECT

public:
	//TickForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent = 0);
	TickForm( QWidget* parent = 0);
	~TickForm();

	void init();
	void shutdown();

	void onTick(Datablk& tick);

private:
	void adjustTableWidget(QTableWidget* tableWidget);
	

private:
	Ui::TickForm* ui;

	QStringList table_col_;
	QMap<QString, int> table_row_;

	//cktrader::ServiceMgr* serviceMgr;
};

#endif