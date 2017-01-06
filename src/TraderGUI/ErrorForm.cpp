#include "ui_ErrorForm.h"
#include "ErrorForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

#include "servicemgr_iml.h"

#include <QTextCodec>

using namespace cktrader;

ErrorForm::ErrorForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::ErrorForm)
{
	ui->setupUi(this);

	this->serviceMgr = serviceMgr;

	codec = QTextCodec::codecForName("gbk");

	//设置列=
	table_col_ << QStringLiteral("错误编号")
		<< QStringLiteral("错误内容")
		<< QStringLiteral("接口");

	this->ui->errorTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->errorTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(this->ui->errorTableWidget);
}

ErrorForm::~ErrorForm()
{
	delete ui;
	ui = nullptr;
}

void ErrorForm::init()
{
	qRegisterMetaType<ErrorData>("ErrorData");
	connect(this, SIGNAL(updateEvent(ErrorData)), this, SLOT(updateContent(ErrorData)));

	this->serviceMgr->getEventEngine()->registerHandler(EVENT_ERROR, std::bind(&ErrorForm::onError, this, std::placeholders::_1), "ErrorForm");
}

void ErrorForm::adjustTableWidget(QTableWidget* tableWidget)
{
	tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft); //设置列左对齐=
	tableWidget->horizontalHeader()->setStretchLastSection(true); //最后一览自适应宽度=
	tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //自适应列宽，不能拖动，会很卡=
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


void ErrorForm::onError(Datablk& error)
{
	ErrorData er = error.cast<ErrorData>();

	emit updateEvent(er);
}

void ErrorForm::updateContent(ErrorData er)
{
	ui->errorTableWidget->insertRow(0);

	QString id = codec->toUnicode(er.errorID.c_str());
	QString content = codec->toUnicode(er.errorMsg.c_str());
	QString gate = codec->toUnicode(er.gateWayName.c_str());
	ui->errorTableWidget->setItem(0, 0, new QTableWidgetItem(id));
	ui->errorTableWidget->setItem(0, 1, new QTableWidgetItem(content));
	ui->errorTableWidget->setItem(0, 2, new QTableWidgetItem(gate));

	ui->errorTableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}