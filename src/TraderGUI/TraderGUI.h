#pragma once

#include <QtWidgets/QMainWindow>

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
class CollapsibleDockWidget;

class QDockWidget;
class QPushButton;

class TraderGUI : public QMainWindow
{
    Q_OBJECT

public:
    TraderGUI(QWidget *parent = Q_NULLPTR);
	~TraderGUI();

	void init();
	void shutdown();

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

	CollapsibleDockWidget* dockWidget_;
	QPushButton* strategyButton_;
	StrategyForm* strategyForm_;
};
