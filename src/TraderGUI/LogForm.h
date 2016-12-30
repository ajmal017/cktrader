#pragma once
#ifndef __LOGFORM_H__
#define __LOGFORM_H__

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
	class LogForm;
}

class LogForm :public QWidget
{
	Q_OBJECT

public:
	LogForm(QWidget* parent = 0);
	~LogForm();

	void init();
	void shutdown();

private:
	void adjustTableWidget(QTableWidget* tableWidget);

private slots:


private:
	Ui::LogForm* ui;
	QStringList table_col_;
};

#endif