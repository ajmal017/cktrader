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
#include "StrategyForm.h"
#include "CtpConfig.h"
#include "CtpLogin.h"
#include "gateway/tgateway_def.h"

#include <QPushButton>
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <QIcon>
#include <QMouseEvent>
#include <QPoint>
#include <iostream>

#include "servicemgr_iml.h"

using namespace cktrader;

TraderGUI::TraderGUI(cktrader::ServiceMgr* mgr, QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::TraderGUIClass)
{
	ui->setupUi(this);

	this->serviceMgr = mgr;

	ui->horizontal_splitter->setHandleWidth(2);
	ui->horizontal_splitter->setStyleSheet("QSplitter::handle{background:#FFFFFF}");

	tickForm_ = new TickForm(mgr,this);
	ui->tabMarket->addTab(tickForm_, QStringLiteral("市场数据"));

	contractForm_ = new ContractForm(mgr,this);
	ui->tabMarket->addTab(contractForm_, QStringLiteral("开市合约"));


	logForm_ = new LogForm(mgr,this);
	ui->tabLeft->addTab(logForm_, QStringLiteral("日志"));

	errorForm_ = new ErrorForm(mgr, this);
	ui->tabLeft->addTab(errorForm_, QStringLiteral("错误"));

	accountForm_ = new AccountForm(mgr, this);
	ui->tabLeft->addTab(accountForm_, QStringLiteral("账户"));

	positionForm_ = new PositionForm(mgr, this);
	ui->tabRight->addTab(positionForm_, QStringLiteral("持仓"));

	orderForm_ = new OrderForm(mgr, this);
	ui->tabRight->addTab(orderForm_, QStringLiteral("委托"));

	tradeForm_ = new TradeForm(mgr, this);
	ui->tabRight->addTab(tradeForm_, QStringLiteral("成交"));

	ui->strategy_widget->resize(300, height());
	ui->strategy_widget->setMinimumWidth(270);
	ui->strategy_widget->setMaximumWidth(300);
		
	strategyForm_ = new StrategyForm(this);
	ui->strategy_widget->setWindowTitle(QStringLiteral("策略管理器"));
	ui->strategy_widget->setLayout(new QGridLayout(ui->strategy_widget));	
	ui->strategy_widget->layout()->addWidget(strategyForm_);

	QPixmap pm = style()->standardPixmap(QStyle::SP_ToolBarHorizontalExtensionButton);

	// Rotate the icon
	QTransform transform;
	transform.rotate(180);
	QPixmap pm_rev = pm.transformed(transform);

	rightIcon = QIcon(pm);
	leftIcon = QIcon(pm_rev);

	spliter_pushButton_ = new QPushButton(this);
	spliter_pushButton_->setFocusPolicy(Qt::NoFocus);
	spliter_pushButton_->setFixedSize(13, 42);
	spliter_pushButton_->setIconSize(spliter_pushButton_->size());
	spliter_pushButton_->setStyleSheet("border:none;");
	spliter_pushButton_->setIcon(leftIcon);
	spliter_pushButton_->move(ui->strategy_widget->width() - (spliter_pushButton_->width()/2)+2, (ui->strategy_widget->height() - spliter_pushButton_->height()) / 2);
	
	ui->ctpActionLogin->setEnabled(false);
	ui->ctpActionConfig->setEnabled(true);

	ui->ltsActionLogin->setEnabled(false);
	ui->ltsActionConfig->setEnabled(true);

	ui->ibActionLogin->setEnabled(false);
	ui->ibActionConfig->setEnabled(true);
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

	delete spliter_pushButton_;
	spliter_pushButton_ = nullptr;
}

void TraderGUI::init()
{
	connect(ui->horizontal_splitter, SIGNAL(splitterMoved(int, int)), this, SLOT(slotSplitterMoved(int, int)));
	connect(spliter_pushButton_, SIGNAL(clicked()), this, SLOT(slotClickedBtn()));

	connect(ui->ctpActionConfig, SIGNAL(triggered()), this, SLOT(ctpActionConfig_triggered()));
	connect(ui->ctpActionLogin, SIGNAL(triggered()), this, SLOT(ctpActionLogin_triggered()));

	connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(quit()));

	tickForm_->init();
	contractForm_->init();
	logForm_->init();
	errorForm_->init();
	accountForm_->init();
	tradeForm_->init();
	orderForm_->init();
	positionForm_->init();
}

void TraderGUI::resizeEvent(QResizeEvent *event)
{
	ui->horizontal_splitter->setGeometry(0, 0, width(), height());
	setBtnIcon();
	setBtnPos();
	//move((QApplication::desktop()->width() - width()) / 2, (QApplication::desktop()->height() - height()) / 2);
	QWidget::resizeEvent(event);
}

void TraderGUI::setBtnPos()
{
	if (ui->strategy_widget->x() >= 0)
	{
		spliter_pushButton_->move(ui->strategy_widget->width() - (spliter_pushButton_->width() / 2), (ui->strategy_widget->height() - spliter_pushButton_->height()) / 2);
	}
	else
	{
		spliter_pushButton_->move(2, (ui->strategy_widget->height() - spliter_pushButton_->height()) / 2);
	}
}

void TraderGUI::setBtnIcon()
{
	if (ui->strategy_widget->x() >= 0) 
	{
		spliter_pushButton_->setIcon(leftIcon);
	}
	else
	{
		spliter_pushButton_->setIcon(rightIcon);
	}
}

void TraderGUI::slotClickedBtn()
{
	QList <int> sizeList;
	sizeList.clear();
	if (ui->strategy_widget->x() >= 0) 
	{
		sizeList.append(0);
		sizeList.append(width());
	}
	else
	{
		sizeList.append(300);
		sizeList.append(width() - 300);
	}
	ui->horizontal_splitter->setSizes(sizeList);

	setBtnIcon();
	setBtnPos();
}

void TraderGUI::slotSplitterMoved(int pos, int index)
{
	Q_UNUSED(pos)
	Q_UNUSED(index)
	setBtnIcon();
	setBtnPos();
}

void TraderGUI::ctpActionLogin_triggered()
{
	CtpLogin dlg(this);
	if (dlg.exec())
	{
		QString password = dlg.getPassword();
		QString userName = dlg.getUserName();
		

#ifdef _DEBUG
		ctp_gate = serviceMgr->loadGateWay("ctp", "CTPGateway-D.dll");
#else
		ctp_gate = serviceMgr->loadGateWay("ctp", "CTPGateway.dll");
#endif
		ctp_gate->connect(userName.toStdString(), password.toStdString());

		//更新ui,接收数据中不要出现模态对话框
		ui->ctpActionLogin->setEnabled(false);
	}
}

void TraderGUI::ctpActionConfig_triggered()
{
	CtpConfig dlg(this);
	dlg.load();
	if (dlg.exec())
	{
		dlg.save();
		ui->ctpActionLogin->setEnabled(true);
	}
}

void TraderGUI::ltsActionLogin_triggered()
{

}

void TraderGUI::ltsActionConfig_triggered()
{

}

void TraderGUI::ibActionLogin_triggered()
{

}

void TraderGUI::ibActionConfig_triggered()
{

}

void TraderGUI::quit()
{
	close();
}

