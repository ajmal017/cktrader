#pragma once
#ifndef __POSITIONFORM_H__
#define __POSITIONFORM_H__

#include <QWidget>
#include <qtablewidget.h>

namespace Ui {
	class PositionForm;
}

class PositionForm :public QWidget
{
	Q_OBJECT

public:
	PositionForm(QWidget* parent = 0);
	~PositionForm();

	void init();
	void shutdown();

private:
	void adjustTableWidget(QTableWidget* tableWidget);

	private slots:

private:
	Ui::PositionForm* ui;
	QStringList table_col_;
};

#endif