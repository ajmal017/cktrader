#pragma once
#ifndef __StrategyPanel_h__
#define __StrategyPanel_h__

#include <QWidget>

namespace Ui {
	class StrategyPanel;
}

class StrategyPanel :public QWidget
{
	Q_OBJECT

public:
	StrategyPanel(QWidget* parent = 0);
	~StrategyPanel();

	void init();

private:
	Ui::StrategyPanel* ui;
};

#endif