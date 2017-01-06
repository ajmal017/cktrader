#include "ui_TickForm.h"
#include "TickForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"
#include "servicemgr_iml.h"

#include <QMessageBox>
#include <QTextCodec>

using namespace cktrader;

TickForm::TickForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TickForm)
{
	this->serviceMgr = serviceMgr;
	ui->setupUi(this);

	codec = QTextCodec::codecForName("gbk");

	this->ui->tickTable->clearContents();
	this->ui->tickTable->setSortingEnabled(false);

	//设置列=
	table_col_ << QStringLiteral("合约代码")
		<< QStringLiteral("合约名称")
		<< QStringLiteral("最新价")

		<< QStringLiteral("成交量")

		<< QStringLiteral("买一价")
		<< QStringLiteral("买一量")
		<< QStringLiteral("卖一价")
		<< QStringLiteral("卖一量")

		<< QStringLiteral("持仓量")
		<< QStringLiteral("开盘价")
		<< QStringLiteral("最高价")
		<< QStringLiteral("最低价")
		
		<< QStringLiteral("时间")

		<< QStringLiteral("涨停价")
		<< QStringLiteral("跌停价")
		<< QStringLiteral("接口");

	this->ui->tickTable->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		ui->tickTable->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(ui->tickTable);

	table_row_.clear();
}

TickForm::~TickForm()
{
	delete ui;
}

void TickForm::init()
{
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_TICK, std::bind(&TickForm::onTick, this, std::placeholders::_1), "TickForm");
	connect(ui->tickTable, SIGNAL(cellClicked(int, int)), this, SLOT(tableWidget_cellClicked(int, int)));
	connect(ui->orderPushButton,SIGNAL(clicked()), this, SLOT(pushButtonSendOrder_clicked()));
	connect(ui->contractLineEdit, SIGNAL(returnPressed()), this, SLOT(contractlineedit_returnPressed()));
}

void TickForm::adjustTableWidget(QTableWidget* tableWidget)
{
	tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft); //设置列左对齐=
	tableWidget->horizontalHeader()->setStretchLastSection(true); //最后一览自适应宽度=
																  //tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //自适应列宽，不能拖动，会很卡=
																  //tableWidget->horizontalHeader()->setDefaultSectionSize(150); //缺省列宽=
	tableWidget->horizontalHeader()->setSectionsClickable(false); //设置表头不可点击=
	tableWidget->horizontalHeader()->setSectionsMovable(false); //设置表头不可点击=
	tableWidget->horizontalHeader()->setHighlightSections(false); //当表格只有一行的时候，则表头会出现塌陷问题=
																  //tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:#FFFFFF;}"); //设置表头背景色=
	tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #FFFFFF, stop: 0.5 #F5F5F5,stop: 0.6 #E8E8E8, stop:1 #FFFFFF);color: black;padding-left:4px; border: 0px; border-right: 1px solid GRAY;border-bottom: 1px solid GRAY;}"); //设置表头背景色=

																																																																												   //tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //自适应行距，不能拖动，会很卡=
	tableWidget->verticalHeader()->setVisible(false); //设置垂直头不可见=

													  //tableWidget->setFrameShape(QFrame::NoFrame); //设置无边框=
													  //tableWidget->setShowGrid(false); //设置不显示格子线=
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑=
	tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //不可多选多行=
																	   //tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //可多选多行=
	tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次选择一行=
	tableWidget->setItemDelegate(new NoFocusDelegate()); // 去鼠标点击出现的虚框=
}

void TickForm::onTick(Datablk& tick)
{
	TickData tick_data = tick.cast<TickData>();

	QVariantMap vItem;
	vItem.insert(QStringLiteral("合约代码"), codec->toUnicode(tick_data.symbol.c_str()));
	// tick里面的exchange不一定有=
	ContractData contract;
	serviceMgr->getContract(tick_data.symbol, contract);
	vItem.insert(QStringLiteral("合约名称"), codec->toUnicode(contract.name.c_str()));
	vItem.insert(QStringLiteral("最新价"), tick_data.lastPrice);
	vItem.insert(QStringLiteral("成交量"), tick_data.volume);
	vItem.insert(QStringLiteral("买一价"), tick_data.bidPrice1);
	vItem.insert(QStringLiteral("买一量"), tick_data.bidVolume1);
	vItem.insert(QStringLiteral("卖一价"), tick_data.askPrice1);
	vItem.insert(QStringLiteral("卖一量"), tick_data.askVolume1);
	vItem.insert(QStringLiteral("持仓量"), tick_data.openInterest);
	vItem.insert(QStringLiteral("开盘价"), tick_data.openPrice);
	vItem.insert(QStringLiteral("最高价"), tick_data.highPrice);
	vItem.insert(QStringLiteral("最低价"), tick_data.lowPrice);
	vItem.insert(QStringLiteral("时间"), codec->toUnicode(tick_data.time.c_str()));
	vItem.insert(QStringLiteral("涨停价"), tick_data.upperLimit);
	vItem.insert(QStringLiteral("跌停价"), tick_data.lowerLimit);
	vItem.insert(QStringLiteral("接口"), codec->toUnicode(tick_data.gateWayName.c_str()));

	//根据id找到对应的行，然后用列的text来在map里面取值设置到item里面=
	QString id = vItem.value(QStringLiteral("合约名称")).toString();
	if (table_row_.contains(id))
	{
		int row = table_row_.value(id);
		for (int i = 0; i < table_col_.count(); i++)
		{
			QVariant raw_val = vItem.value(table_col_.at(i));
			QString str_val = raw_val.toString();
			if (raw_val.type() == QMetaType::Double || raw_val.type() == QMetaType::Float)
			{
				str_val = QString().sprintf("%6.3f", raw_val.toDouble());
			}

			QTableWidgetItem* item = new QTableWidgetItem(str_val);
			ui->tickTable->setItem(row, i, item);
		}
	}
	else
	{
		int row = table_row_.size();
		ui->tickTable->insertRow(row);
		table_row_.insert(id, row);

		for (int i = 0; i < table_col_.count(); i++)
		{
			QVariant raw_val = vItem.value(table_col_.at(i));
			QString str_val = raw_val.toString();
			if (raw_val.type() == QMetaType::Double || raw_val.type() == QMetaType::Float)
			{
				str_val = QString().sprintf("%6.3f", raw_val.toDouble());
			}

			QTableWidgetItem* item = new QTableWidgetItem(str_val);
			ui->tickTable->setItem(row, i, item);
		}
	}
	
}

void TickForm::pushButtonSendOrder_clicked()
{
	QString symbol = ui->contractLineEdit->text();
	double price = ui->priceDoubleSpinBox->value();
	double volume = ui->volDoubleSpinBox->value();

	QString priceType = ui->priceTypeComboBox->currentData().toString();
	QString direction = ui->directionComboBox->currentData().toString();
	QString offset = ui->offsetComboBox->currentData().toString();
	QString currency = ui->currencyComboBox->currentData().toString();

	OrderReq req;
	req.symbol = symbol.toStdString();
	ContractData cn;
	serviceMgr->getContract(req.symbol, cn);

	req.exchange = cn.exchange;
	req.price = price;
	req.volume = volume;
	req.priceType = priceType.toStdString();
	req.direction = offset.toStdString();
	req.currency = currency.toStdString();

	IGateway* pGateway = serviceMgr->getGateWay(cn.gateWayName);

	if (pGateway)
	{
		pGateway->sendOrder(req);
	}
	else
	{
		QStringList x;
		x << cn.gateWayName.c_str()
			<< QStringLiteral("不存在，请确认是否登录");

		QMessageBox::critical(this, QStringLiteral("未找到Gateway"),x.join(","));
	}
}

void TickForm::tableWidget_cellClicked(int row, int column)
{
	(void)column;

	QString symbol = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("合约代码")))->text();
	auto item = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("最新价")));
	double lastPrice = item ? item->text().toDouble() : 0.0;
	item = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("涨停价")));
	double upperLimit = item ? item->text().toDouble() : 0.0;
	item = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("跌停价")));
	double lowerLimit = item ? item->text().toDouble() : 0.0;

	ui->contractLineEdit->setText(symbol);

	//设置price
	ui->priceDoubleSpinBox->setValue(lastPrice);
	ui->priceDoubleSpinBox->setMaximum(upperLimit);
	ui->priceDoubleSpinBox->setMinimum(lowerLimit);

	ContractData cn;
	bool havecontract = serviceMgr->getContract(symbol.toStdString(), cn);

	if (havecontract) 
	{
		ui->priceDoubleSpinBox->setSingleStep(cn.priceTick);
	}
}

void  TickForm::contractlineedit_returnPressed()
{
	QString symbol = ui->contractLineEdit->text();

	ContractData cn;
	bool havecontract = serviceMgr->getContract(symbol.toStdString(), cn);

	if (havecontract)
	{
		IGateway* pGateway = serviceMgr->getGateWay(cn.gateWayName);
		SubscribeReq req;
		req.symbol = symbol.toStdString();
		pGateway->subscribe(req);
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("错误"), QStringLiteral("没有此合约"));
	}
}