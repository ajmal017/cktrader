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
	//������=
	table_col_ << QStringLiteral("��Լ����")
		<< QStringLiteral("������")
		<< QStringLiteral("��Լ����")

		<< QStringLiteral("��Լ����")
		<< QStringLiteral("�۸�䶯��λ")
		<< QStringLiteral("��С");

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

void ContractForm::onContract(Datablk& contract)
{
	ContractData cn = contract.cast<ContractData>();

	QVariantMap vItem;
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(cn.symbol.c_str()));
	vItem.insert(QStringLiteral("������"), codec->toUnicode(cn.exchange.c_str()));
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(cn.name.c_str()));
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(cn.productClass.c_str()));
	vItem.insert(QStringLiteral("�۸�䶯��λ"), cn.priceTick);
	vItem.insert(QStringLiteral("��С"), cn.size);

	//����id�ҵ���Ӧ���У�Ȼ�����е�text����map����ȡֵ���õ�item����=
	QString id = vItem.value(QStringLiteral("��Լ����")).toString();
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