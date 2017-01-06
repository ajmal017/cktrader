#include "ui_AccountForm.h"
#include "AccountForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

#include "servicemgr_iml.h"

#include <QTextCodec>

using namespace cktrader;

AccountForm::AccountForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::AccountForm)
{
	ui->setupUi(this);

	this->serviceMgr = serviceMgr;

	codec = QTextCodec::codecForName("gbk");

	//������=
	table_col_ << QStringLiteral("�˻�")
		<< QStringLiteral("���")
		<< QStringLiteral("��ֵ")
		<< QStringLiteral("����")
		<< QStringLiteral("������")
		<< QStringLiteral("��֤��")
		<< QStringLiteral("ƽ��ӯ��")
		<< QStringLiteral("�ֲ�ӯ��")
		<< QStringLiteral("�ӿ�");

	this->ui->accountTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->accountTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(this->ui->accountTableWidget);
}

AccountForm::~AccountForm()
{
	delete ui;
	ui = nullptr;
}

void AccountForm::init()
{
	qRegisterMetaType<AccountData>("AccountData");
	connect(this, SIGNAL(updateEvent(AccountData)), this, SLOT(updateContent(AccountData)));
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_ACCOUNT, std::bind(&AccountForm::onAccount, this, std::placeholders::_1), "AccountForm");
}

void AccountForm::adjustTableWidget(QTableWidget* tableWidget)
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

void AccountForm::onAccount(Datablk& account)
{
	AccountData ac = account.cast<AccountData>();

	emit updateEvent(ac);
}

void AccountForm::updateContent(AccountData ac)
{
	QVariantMap vItem;
	vItem.insert(QStringLiteral("�˻�"), codec->toUnicode(ac.accountID.c_str()));

	vItem.insert(QStringLiteral("���"), ac.preBalance);
	vItem.insert(QStringLiteral("��ֵ"), ac.balance);

	if (ac.available<=0)
	{
		vItem.insert(QStringLiteral("����"), 0);
	}
	else
	{
		vItem.insert(QStringLiteral("����"), ac.available);
	}
	
	vItem.insert(QStringLiteral("������"), ac.commission);
	vItem.insert(QStringLiteral("��֤��"), ac.margin);
	vItem.insert(QStringLiteral("ƽ��ӯ��"), ac.closeProfit);
	vItem.insert(QStringLiteral("�ֲ�ӯ��"), ac.positionProfit);
	vItem.insert(QStringLiteral("�ӿ�"), codec->toUnicode(ac.gateWayName.c_str()));


	//����id�ҵ���Ӧ���У�Ȼ�����е�text����map����ȡֵ���õ�item����=
	QString id = vItem.value(QStringLiteral("�˻�")).toString();
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

			ui->accountTableWidget->item(row, i)->setText(str_val);

			//QTableWidgetItem* item = new QTableWidgetItem(str_val);
			//ui->tickTable->setItem(row, i, item);
		}
	}
	else
	{
		int row = table_row_.size();
		ui->accountTableWidget->insertRow(row);
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
			ui->accountTableWidget->setItem(row, i, item);
		}
	}
}