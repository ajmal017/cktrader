#pragma once
#ifndef __tradergui_h__
#define __tradergui_h__
#include <QtWidgets/QMainWindow>

namespace cktrader {
	class ServiceMgr;
	class IGateway;
}

namespace Ui {
	class TraderGUIClass;
}

class TickForm;
class ContractForm;
class LogForm;
class ErrorForm;
class AccountForm;
class TradeForm;
class OrderForm;
class PositionForm;
class StrategyForm;
class QPushButton;
class QPoint;

class TraderGUI : public QMainWindow
{
    Q_OBJECT

public:
    TraderGUI(cktrader::ServiceMgr* mgr,QWidget *parent = Q_NULLPTR);
	~TraderGUI();

	void init();

protected:
	void resizeEvent(QResizeEvent *event);


private:
	void setBtnPos();
	void setBtnIcon();

private slots:
	void slotClickedBtn();
	void slotSplitterMoved(int pos, int index);
	void ctpActionLogin_triggered();
	void ctpActionLogout_triggered();
	void ctpActionConfig_triggered();
	void ltsActionLogin_triggered();
	void ltsActionLogout_triggered();
	void ltsActionConfig_triggered();
	void ibActionLogin_triggered();
	void ibActionLogout_triggered();
	void ibActionConfig_triggered();

	void quit();

private:
    Ui::TraderGUIClass* ui;

	TickForm* tickForm_;
	ContractForm* contractForm_;
	LogForm* logForm_;
	ErrorForm* errorForm_;
	AccountForm* accountForm_;
	TradeForm* tradeForm_;
	OrderForm* orderForm_;
	PositionForm* positionForm_;

	StrategyForm* strategyForm_;

	QPushButton* spliter_pushButton_;
	QIcon leftIcon;
	QIcon rightIcon;

	cktrader::ServiceMgr* serviceMgr;
	cktrader::IGateway* ctp_gate;
};

#endif
