#include "TraderGUI.h"
#include "ui_TraderGUI.h"
#include "TickForm.h"
#include "ContractForm.h"
#include "LogForm.h"
#include "ErrorForm.h"
#include "AccountForm.h"
#include "TradeForm.h"
#include "OrderForm.h"
#include "PositionForm.h"
#include "CollapsibleDockWidget.h"
#include "StrategyForm.h"

#include <QPushButton>

TraderGUI::TraderGUI(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::TraderGUIClass)
{
	ui->setupUi(this);

	tickForm_ = new TickForm(this);
	ui->tabMarket->addTab(tickForm_, QStringLiteral("市场数据"));

	contractForm_ = new ContractForm(this);
	ui->tabMarket->addTab(contractForm_, QStringLiteral("开市合约"));


	logForm_ = new LogForm(this);
	ui->tabLeft->addTab(logForm_, QStringLiteral("日志"));

	errorForm_ = new ErrorForm(this);
	ui->tabLeft->addTab(errorForm_, QStringLiteral("错误"));

	accountForm_ = new AccountForm(this);
	ui->tabLeft->addTab(accountForm_, QStringLiteral("账户"));


	tradeForm_ = new TradeForm(this);
	ui->tabRight->addTab(tradeForm_, QStringLiteral("成交"));

	orderForm_ = new OrderForm(this);
	ui->tabRight->addTab(orderForm_, QStringLiteral("委托"));

	positionForm_ = new PositionForm(this);
	ui->tabRight->addTab(positionForm_, QStringLiteral("持仓"));

	setDockOptions(QMainWindow::AnimatedDocks);
	dockWidget_ = new CollapsibleDockWidget(this);
	dockWidget_->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable);
	dockWidget_->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

	strategyButton_ = new QPushButton(this);
	strategyButton_->resize(50, 20);
	strategyButton_->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	strategyButton_->setText(QStringLiteral("策略"));

	strategyForm_ = new StrategyForm(this);

	dockWidget_->setAnimationEnabled(true);
	dockWidget_->setExpandedWidget(strategyForm_);
	dockWidget_->setCollapsedWidget(strategyButton_);
	dockWidget_->setExpanded(true);
	
	addDockWidget(Qt::LeftDockWidgetArea, dockWidget_);
}

TraderGUI::~TraderGUI()
{
	delete ui;
	ui = nullptr;

	delete tickForm_;
	tickForm_ = nullptr;

	delete contractForm_;
	contractForm_ = nullptr;

	delete errorForm_;
	errorForm_ = nullptr;

	delete accountForm_;
	accountForm_ = nullptr;

	delete tradeForm_;
	tradeForm_ = nullptr;

	delete orderForm_;
	orderForm_ = nullptr;

	delete positionForm_;
	positionForm_ = nullptr;

	delete strategyForm_;
	strategyForm_ = nullptr;
}

void TraderGUI::init()
{

}
void TraderGUI::shutdown()
{

}
