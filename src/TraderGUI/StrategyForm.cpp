#include "StrategyForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"
#include "qpushbutton.h"
#include "widgetbox.h"

#include <QVBoxLayout> 
#include <QHBoxLayout>

StrategyForm::StrategyForm(QWidget* parent)
	:QWidget(parent)
{
	load_strategy_button = new QPushButton(QStringLiteral("加载策略"),parent);
	init_all_strategy_button = new QPushButton(QStringLiteral("初始化策略"), parent);
	start_all_strategy_button = new QPushButton(QStringLiteral("开始交易"), parent);
	stop_all_strategy_button = new QPushButton(QStringLiteral("关闭策略"), parent);

	layout = new QVBoxLayout(parent);

	button_layout = new QHBoxLayout(parent);
	button_layout->addWidget(load_strategy_button);
	button_layout->addWidget(init_all_strategy_button);
	button_layout->addWidget(start_all_strategy_button);
	button_layout->addWidget(stop_all_strategy_button);

	strategy_box = new WidgetBox(parent);

	layout->addItem(button_layout);
	layout->addWidget(strategy_box);

	setLayout(layout);
}

StrategyForm::~StrategyForm()
{
	delete load_strategy_button;
	load_strategy_button = nullptr;

	delete init_all_strategy_button;
	init_all_strategy_button = nullptr;

	delete start_all_strategy_button;
	start_all_strategy_button = nullptr;

	delete stop_all_strategy_button;
	stop_all_strategy_button = nullptr;

	delete strategy_box;
	strategy_box = nullptr;
}

void StrategyForm::init()
{

}