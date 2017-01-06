#include "ui_OrderForm.h"
#include "OrderForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

#include "servicemgr_iml.h"

#include <QTextCodec>

OrderForm::OrderForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::OrderForm)
{
	ui->setupUi(this);

	this->serviceMgr = serviceMgr;

	codec = QTextCodec::codecForName("gbk");

	//设置列=
	table_col_ << QStringLiteral("委托编号")
		<< QStringLiteral("合约代码")
		<< QStringLiteral("方向")
		<< QStringLiteral("开平")
		<< QStringLiteral("价格")
		<< QStringLiteral("委托数量")
		<< QStringLiteral("成交数量")
		<< QStringLiteral("状态")
		<< QStringLiteral("撤销时间")
		<< QStringLiteral("前置编号")
		<< QStringLiteral("会话编号")
		<< QStringLiteral("接口");

	this->ui->orderTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->orderTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(this->ui->orderTableWidget);
}

OrderForm::~OrderForm()
{
	delete ui;
	ui = nullptr;
}

void OrderForm::init()
{
	qRegisterMetaType<OrderData>("OrderData");
	connect(this, SIGNAL(updateEvent(OrderData)), this, SLOT(updateContent(OrderData)));
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_ORDER, std::bind(&OrderForm::onOrder, this, std::placeholders::_1), "OrderForm");
}

void OrderForm::adjustTableWidget(QTableWidget* tableWidget)
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

void OrderForm::onOrder(Datablk& or )
{
	OrderData order = or .cast<OrderData>();

	emit updateEvent(order);
}

void OrderForm::updateContent(OrderData order)
{
	QVariantMap vItem;
	vItem.insert(QStringLiteral("委托编号"), codec->toUnicode(order.orderID.c_str()));

	vItem.insert(QStringLiteral("合约代码"), codec->toUnicode(order.symbol.c_str()));
	vItem.insert(QStringLiteral("方向"), codec->toUnicode(order.direction.c_str()));
	vItem.insert(QStringLiteral("开平"), codec->toUnicode(order.offset.c_str()));
	vItem.insert(QStringLiteral("价格"), order.price);
	vItem.insert(QStringLiteral("委托数量"), order.totalVolume);
	vItem.insert(QStringLiteral("成交数量"), order.tradedVolume);
	vItem.insert(QStringLiteral("状态"), codec->toUnicode(order.status.c_str()));
	vItem.insert(QStringLiteral("撤销时间"), codec->toUnicode(order.cancelTime.c_str()));
	vItem.insert(QStringLiteral("前置编号"), order.frontID);
	vItem.insert(QStringLiteral("会话编号"), order.sessionID);
	vItem.insert(QStringLiteral("接口"), codec->toUnicode(order.gateWayName.c_str()));


	//根据id找到对应的行，然后用列的text来在map里面取值设置到item里面=
	QString id = vItem.value(QStringLiteral("委托编号")).toString();
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

			ui->orderTableWidget->item(row, i)->setText(str_val);

			//QTableWidgetItem* item = new QTableWidgetItem(str_val);
			//ui->tickTable->setItem(row, i, item);
		}
	}
	else
	{
		int row = table_row_.size();
		ui->orderTableWidget->insertRow(row);
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
			ui->orderTableWidget->setItem(row, i, item);
		}
	}
}