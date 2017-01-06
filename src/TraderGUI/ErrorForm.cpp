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

	//������=
	table_col_ << QStringLiteral("������")
		<< QStringLiteral("��������")
		<< QStringLiteral("�ӿ�");

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
	tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft); //�����������=
	tableWidget->horizontalHeader()->setStretchLastSection(true); //���һ������Ӧ���=
	tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //����Ӧ�п������϶�����ܿ�=
																  //tableWidget->horizontalHeader()->setDefaultSectionSize(150); //ȱʡ�п�=
	tableWidget->horizontalHeader()->setSectionsClickable(false); //���ñ�ͷ���ɵ��=
	tableWidget->horizontalHeader()->setSectionsMovable(false); //���ñ�ͷ���ɵ��=
	tableWidget->horizontalHeader()->setHighlightSections(false); //�����ֻ��һ�е�ʱ�����ͷ�������������=
																  //tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background:#FFFFFF;}"); //���ñ�ͷ����ɫ=
	tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,stop:0 #FFFFFF, stop: 0.5 #F5F5F5,stop: 0.6 #E8E8E8, stop:1 #FFFFFF);color: black;padding-left:4px; border: 0px; border-right: 1px solid GRAY;border-bottom: 1px solid GRAY;}"); //���ñ�ͷ����ɫ=

																																																																												   //tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //����Ӧ�о࣬�����϶�����ܿ�=
	tableWidget->verticalHeader()->setVisible(false); //���ô�ֱͷ���ɼ�=

													  //tableWidget->setFrameShape(QFrame::NoFrame); //�����ޱ߿�=
													  //tableWidget->setShowGrid(false); //���ò���ʾ������=
	tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭=
	tableWidget->setSelectionMode(QAbstractItemView::SingleSelection); //���ɶ�ѡ����=
																	   //tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); //�ɶ�ѡ����=
	tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ����Ϊʱÿ��ѡ��һ��=
	tableWidget->setItemDelegate(new NoFocusDelegate()); // ȥ��������ֵ����=
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