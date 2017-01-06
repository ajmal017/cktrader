#include "ui_ContractForm.h"
#include "ContractForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

#include "servicemgr_iml.h"

#include <QTextCodec>

using namespace cktrader;

ContractForm::ContractForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::ContractForm)
{
	ui->setupUi(this);

	codec = QTextCodec::codecForName("gbk");

	this->ui->ContractTableWidget->clearContents();
	this->ui->ContractTableWidget->setSortingEnabled(false);

	this->serviceMgr = serviceMgr;
	//设置列=
	table_col_ << QStringLiteral("合约代码")
		<< QStringLiteral("交易所")
		<< QStringLiteral("合约名称")

		<< QStringLiteral("合约类型")
		<< QStringLiteral("价格变动单位")
		<< QStringLiteral("大小");

	this->ui->ContractTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->ContractTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	this->adjustTableWidget(this->ui->ContractTableWidget);
}

ContractForm::~ContractForm()
{
	delete ui;
	ui = nullptr;
}

void ContractForm::init()
{
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_CONTRACT, std::bind(&ContractForm::onContract, this, std::placeholders::_1), "ContractForm");
}

void ContractForm::adjustTableWidget(QTableWidget* tableWidget)
{
	tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft); //设置列左对齐=
	tableWidget->horizontalHeader()->setStretchLastSection(false); //最后一览自适应宽度=
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

void ContractForm::onContract(Datablk& contract)
{
	ContractData cn = contract.cast<ContractData>();

	QVariantMap vItem;
	vItem.insert(QStringLiteral("合约代码"), codec->toUnicode(cn.symbol.c_str()));
	vItem.insert(QStringLiteral("交易所"), codec->toUnicode(cn.exchange.c_str()));
	vItem.insert(QStringLiteral("合约名称"), codec->toUnicode(cn.name.c_str()));
	vItem.insert(QStringLiteral("合约类型"), codec->toUnicode(cn.productClass.c_str()));
	vItem.insert(QStringLiteral("价格变动单位"), cn.priceTick);
	vItem.insert(QStringLiteral("大小"), cn.size);

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
			ui->ContractTableWidget->setItem(row, i, item);
		}
	}
	else
	{
		int row = table_row_.size();
		ui->ContractTableWidget->insertRow(row);
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
			ui->ContractTableWidget->setItem(row, i, item);
		}
	}
}