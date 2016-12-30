#pragma once
#ifndef __ERRORFORM_H__
#define __ERRORFORM_H__

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
	class ErrorForm;
}

class ErrorForm :public QWidget
{
	Q_OBJECT

public:
	ErrorForm(QWidget* parent = 0);
	~ErrorForm();

	void init();
	void shutdown();

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:


private:
	Ui::ErrorForm* ui;
	QStringList table_col_;
};

#endif