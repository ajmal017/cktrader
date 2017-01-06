#include "ui_LogForm.h"
#include "LogForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

#include "servicemgr_iml.h"

#include <QTextCodec>

using namespace cktrader;

LogForm::LogForm(ServiceMgr* serviceMgr,QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::LogForm)
{
	ui->setupUi(this);

	this->serviceMgr = serviceMgr;

	codec = QTextCodec::codecForName("gbk");

	//������=
	table_col_ << QStringLiteral("����")
		<< QStringLiteral("�ӿ�");

	this->ui->logTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->logTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(this->ui->logTableWidget);
}

LogForm::~LogForm()
{
	delete ui;
	ui = nullptr;
}

void LogForm::init()
{
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_LOG, std::bind(&LogForm::onLog, this, std::placeholders::_1), "LogForm");
}

void LogForm::adjustTableWidget(QTableWidget* tableWidget)
{
	tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft); //�����������=
	tableWidget->horizontalHeader()->setStretchLastSection(false); //���һ������Ӧ���=
																  //tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //����Ӧ�п������϶�����ܿ�=
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

void LogForm::onLog(Datablk& log)
{
	LogData log_data = log.cast<LogData>();

	ui->logTableWidget->insertRow(0);

	QString content = codec->toUnicode(log_data.logContent.c_str());
	QString gate = codec->toUnicode(log_data.gateWayName.c_str());
	ui->logTableWidget->setItem(0, 0, new QTableWidgetItem(content));
	ui->logTableWidget->setItem(0, 1, new QTableWidgetItem(gate));
}