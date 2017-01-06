#pragma once
#ifndef __POSITIONFORM_H__
#define __POSITIONFORM_H__

#include <QWidget>
#include <qtablewidget.h>

#include "utils/ckdef.h"
#include "utils/cktypes.h"

namespace Ui {
	class PositionForm;
}

namespace cktrader {
	class ServiceMgr;
}

class PositionForm :public QWidget
{
	Q_OBJECT

public:
	PositionForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent = 0);
	~PositionForm();

	void init();

	void onPosition(Datablk& pos);

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:
	void updateContent(PositionData pos);

signals:
	void updateEvent(PositionData pos);

private:
	Ui::PositionForm* ui;
	QStringList table_col_;
	QMap<QString, int> table_row_;

	cktrader::ServiceMgr* serviceMgr;

	QTextCodec * codec;
};

#endif