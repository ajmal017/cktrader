#include "ui_OrderForm.h"
#include "OrderForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

OrderForm::OrderForm(QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::OrderForm)
{
	ui->setupUi(this);

	//设置列=
	table_col_ << QStringLiteral("委托编号")
		<< QStringLiteral("合约代码")
		<< QStringLiteral("名称")
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

}

void OrderForm::shutdown()
{

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