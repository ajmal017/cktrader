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

	//������=
	table_col_ << QStringLiteral("ί�б��")
		<< QStringLiteral("��Լ����")
		<< QStringLiteral("����")
		<< QStringLiteral("��ƽ")
		<< QStringLiteral("�۸�")
		<< QStringLiteral("ί������")
		<< QStringLiteral("�ɽ�����")
		<< QStringLiteral("״̬")
		<< QStringLiteral("����ʱ��")
		<< QStringLiteral("ǰ�ñ��")
		<< QStringLiteral("�Ự���")
		<< QStringLiteral("�ӿ�");

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

void OrderForm::onOrder(Datablk& or )
{
	OrderData order = or .cast<OrderData>();

	emit updateEvent(order);
}

void OrderForm::updateContent(OrderData order)
{
	QVariantMap vItem;
	vItem.insert(QStringLiteral("ί�б��"), codec->toUnicode(order.orderID.c_str()));

	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(order.symbol.c_str()));
	vItem.insert(QStringLiteral("����"), codec->toUnicode(order.direction.c_str()));
	vItem.insert(QStringLiteral("��ƽ"), codec->toUnicode(order.offset.c_str()));
	vItem.insert(QStringLiteral("�۸�"), order.price);
	vItem.insert(QStringLiteral("ί������"), order.totalVolume);
	vItem.insert(QStringLiteral("�ɽ�����"), order.tradedVolume);
	vItem.insert(QStringLiteral("״̬"), codec->toUnicode(order.status.c_str()));
	vItem.insert(QStringLiteral("����ʱ��"), codec->toUnicode(order.cancelTime.c_str()));
	vItem.insert(QStringLiteral("ǰ�ñ��"), order.frontID);
	vItem.insert(QStringLiteral("�Ự���"), order.sessionID);
	vItem.insert(QStringLiteral("�ӿ�"), codec->toUnicode(order.gateWayName.c_str()));


	//����id�ҵ���Ӧ���У�Ȼ�����е�text����map����ȡֵ���õ�item����=
	QString id = vItem.value(QStringLiteral("ί�б��")).toString();
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