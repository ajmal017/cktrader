#pragma once
#ifndef __ERRORFORM_H__
#define __ERRORFORM_H__

#include <QWidget>
#include <qtablewidget.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class ErrorForm;
}

namespace cktrader {
	class ServiceMgr;
}

class ErrorForm :public QWidget
{
	Q_OBJECT

public:
	ErrorForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent = 0);
	~ErrorForm();

	void init();

	void onError(Datablk& error);

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:
	void updateContent(ErrorData er);

signals:
	void updateEvent(ErrorData er);

private:
	Ui::ErrorForm* ui;
	QStringList table_col_;

	QTextCodec * codec;

	cktrader::ServiceMgr* serviceMgr;
};

#endif