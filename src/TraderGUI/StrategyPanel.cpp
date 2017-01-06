#include "ui_StrategyPanel.h"
#include "StrategyPanel.h"

StrategyPanel::StrategyPanel(QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::StrategyPanel)
{
	ui->setupUi(this);
}

StrategyPanel::~StrategyPanel()
{
	delete ui;
	ui = nullptr;
}

void StrategyPanel::init()
{

}

