#include "ui_PositionForm.h"
#include "PositionForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

PositionForm::PositionForm(QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::PositionForm)
{
	ui->setupUi(this);

	//������=
	table_col_ << QStringLiteral("��Լ����")
		<< QStringLiteral("����")
		<< QStringLiteral("����")
		<< QStringLiteral("�ֲ���")
		<< QStringLiteral("��ֲ�")
		<< QStringLiteral("������")
		<< QStringLiteral("�۸�")
		<< QStringLiteral("�ӿ�");

	this->ui->positionTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->positionTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(this->ui->positionTableWidget);
}

PositionForm::~PositionForm()
{
	delete ui;
	ui = nullptr;
}

void PositionForm::init()
{

}

void PositionForm::shutdown()
{

}

void PositionForm::adjustTableWidget(QTableWidget* tableWidget)
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