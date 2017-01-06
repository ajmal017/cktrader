
#include "StrategyPanel.h"
#include "NoFocusDelegate.h"
#include "qstring.h"
#include "qpushbutton.h"
#include "widgetbox.h"
#include "StrategyForm.h"

#include <QVBoxLayout> 
#include <QHBoxLayout>

StrategyForm::StrategyForm(QWidget* parent)
	:QWidget(parent)
{
	load_strategy_button = new QPushButton(QStringLiteral("���ز���"),parent);
	init_all_strategy_button = new QPushButton(QStringLiteral("��ʼ������"), parent);
	start_all_strategy_button = new QPushButton(QStringLiteral("��ʼ����"), parent);
	stop_all_strategy_button = new QPushButton(QStringLiteral("�رս���"), parent);

	layout = new QVBoxLayout(parent);

	stratey_button_layout = new QHBoxLayout(parent);
	stratey_button_layout->addWidget(load_strategy_button);
	stratey_button_layout->addWidget(init_all_strategy_button);
	trade_button_layout = new QHBoxLayout(parent);
	trade_button_layout->addWidget(start_all_strategy_button);
	trade_button_layout->addWidget(stop_all_strategy_button);

	strategy_box = new WidgetBox(parent);	
	for (int i = 0; i < 12; i++)
	{
		StrategyPanel* x = new StrategyPanel(this);
		x->setWindowTitle(QStringLiteral("˫����"));
		strategy_box->addPage(x);
	}

	layout->addItem(stratey_button_layout);
	layout->addItem(trade_button_layout);
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