#pragma once
#ifndef __CONTRACTFORM_H__
#define __CONTRACTFORM_H__

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
	class ContractForm;
}

class ContractForm :public QWidget
{
	Q_OBJECT

public:
	ContractForm(QWidget* parent = 0);
	~ContractForm();

	void init();
	void shutdown();

private:
	void adjustTableWidget(QTableWidget* tableWidget);

	private slots:


private:
	Ui::ContractForm* ui;
	QStringList table_col_;
};

#endif