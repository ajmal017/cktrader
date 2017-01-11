#include "ui_TradeForm.h"
#include "TradeForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

#include "servicemgr_iml.h"

#include <QTextCodec>

TradeForm::TradeForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::TradeForm)
{
	ui->setupUi(this);

	this->serviceMgr = serviceMgr;

	codec = QTextCodec::codecForName("gbk");

	//设置列=
	table_col_ << QStringLiteral("成交编号")
		<< QStringLiteral("委托编号")
		<< QStringLiteral("合约代码")
		<< QStringLiteral("方向")
		<< QStringLiteral("开平")
		<< QStringLiteral("价格")
		<< QStringLiteral("数量")
		<< QStringLiteral("成交时间")
		<< QStringLiteral("接口");

	this->ui->tradeTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->tradeTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(ui->tradeTableWidget);
}

TradeForm::~TradeForm()
{
	delete ui;
	ui = nullptr;
}

void TradeForm::init()
{
	qRegisterMetaType<TradeData>("TradeData");
	connect(this, SIGNAL(updateEvent(TradeData)), this, SLOT(updateContent(TradeData)), Qt::QueuedConnection);
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_TRADE, std::bind(&TradeForm::onTrade, this, std::placeholders::_1), "TradeForm");
}

void TradeForm::adjustTableWidget(QTableWidget* tableWidget)
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

void TradeForm::onTrade(Datablk& tr)
{
	TradeData trade = tr.cast<TradeData>();

	emit updateEvent(trade);
}

void TradeForm::updateContent(TradeData trade)
{
	QVariantMap vItem;
	vItem.insert(QStringLiteral("成交编号"), codec->toUnicode(trade.tradeID.c_str()));

	vItem.insert(QStringLiteral("委托编号"), codec->toUnicode(trade.orderID.c_str()));
	vItem.insert(QStringLiteral("合约代码"), codec->toUnicode(trade.symbol.c_str()));
	vItem.insert(QStringLiteral("方向"), codec->toUnicode(trade.direction.c_str()));
	vItem.insert(QStringLiteral("开平"), codec->toUnicode(trade.offset.c_str()));
	vItem.insert(QStringLiteral("价格"), trade.price);
	vItem.insert(QStringLiteral("数量"), trade.volume);
	vItem.insert(QStringLiteral("成交时间"), codec->toUnicode(trade.tradeTime.c_str()));
	vItem.insert(QStringLiteral("接口"), codec->toUnicode(trade.gateWayName.c_str()));


	//根据id找到对应的行，然后用列的text来在map里面取值设置到item里面=
	QString id = vItem.value(QStringLiteral("成交编号")).toString();
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

			ui->tradeTableWidget->item(row, i)->setText(str_val);

			//QTableWidgetItem* item = new QTableWidgetItem(str_val);
			//ui->tickTable->setItem(row, i, item);
		}
	}
	else
	{
		int row = table_row_.size();
		ui->tradeTableWidget->insertRow(row);
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
			ui->tradeTableWidget->setItem(row, i, item);
		}
	}

	ui->tradeTableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}