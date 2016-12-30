
#include "ui_TickForm.h"
#include "TickForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"
#include "servicemgr_iml.h"

using namespace cktrader;

//TickForm::TickForm(ServiceMgr* serviceMgr, QWidget* parent)
TickForm::TickForm(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TickForm)
{
	//this->serviceMgr = serviceMgr;
	ui->setupUi(this);

	//������=
	table_col_ << QStringLiteral("��Լ����")
		<< QStringLiteral("��Լ����")
		<< QStringLiteral("���¼�")

		<< QStringLiteral("�ɽ���")
		<< QStringLiteral("�ֲ���")
		<< QStringLiteral("���̼�")
		<< QStringLiteral("��߼�")
		<< QStringLiteral("��ͼ�")

		
		<< QStringLiteral("��һ��")
		<< QStringLiteral("��һ��")
		<< QStringLiteral("��һ��")
		<< QStringLiteral("��һ��")
		
		<< QStringLiteral("ʱ��")

		<< QStringLiteral("��ͣ��")
		<< QStringLiteral("��ͣ��");

	this->ui->tickTable->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		ui->tickTable->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(ui->tickTable);
}

TickForm::~TickForm()
{
	delete ui;
}

void TickForm::init()
{

}

void TickForm::shutdown()
{

}

void TickForm::adjustTableWidget(QTableWidget* tableWidget)
{
	tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft); //�����������=
	tableWidget->horizontalHeader()->setStretchLastSection(true); //���һ������Ӧ���=
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

void TickForm::onTick(Datablk& tick)
{
	TickData tick_data = tick.cast<TickData>();
}