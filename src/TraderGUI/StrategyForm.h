#pragma once
#ifndef __StrategyForm_h__
#define __StrategyForm_h__

#include <QWidget>

class QPushButton;
class WidgetBox;
class QVBoxLayout;
class QHBoxLayout;

class StrategyForm:public QWidget
{
	Q_OBJECT

public:
	StrategyForm(QWidget* parent = 0);
	~StrategyForm();

	void init();

private:
	QPushButton* load_strategy_button;
	QPushButton* init_all_strategy_button;
	QPushButton* start_all_strategy_button;
	QPushButton* stop_all_strategy_button;

	QHBoxLayout* button_layout;
	QVBoxLayout* layout;

	WidgetBox* strategy_box;
};

#endif