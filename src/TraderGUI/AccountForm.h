#pragma once
#ifndef __ACCOUNTFORM_H__
#define __ACCOUNTFORM_H__

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
	class AccountForm;
}

class AccountForm :public QWidget
{
	Q_OBJECT

public:
	AccountForm(QWidget* parent = 0);
	~AccountForm();

	void init();
	void shutdown();

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:

private:
	Ui::AccountForm* ui;
	QStringList table_col_;
};

#endif