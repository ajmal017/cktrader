#include "ui_TradeForm.h"
#include "TradeForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"

#include "servicemgr_iml.h"

#include <QTextCodec>

TradeForm::TradeForm(cktrader::ServiceMgr* serviceMgr, QWidget* parent)
	:QWidget(parent)
	, ui(new Ui::TradeForm)
{
	ui->setupUi(this);

	this->serviceMgr = serviceMgr;

	codec = QTextCodec::codecForName("gbk");

	//������=
	table_col_ << QStringLiteral("�ɽ����")
		<< QStringLiteral("ί�б��")
		<< QStringLiteral("��Լ����")
		<< QStringLiteral("����")
		<< QStringLiteral("��ƽ")
		<< QStringLiteral("�۸�")
		<< QStringLiteral("����")
		<< QStringLiteral("�ɽ�ʱ��")
		<< QStringLiteral("�ӿ�");

	this->ui->tradeTableWidget->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		this->ui->tradeTableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(ui->tradeTableWidget);
}

TradeForm::~TradeForm()
{
	delete ui;
	ui = nullptr;
}

void TradeForm::init()
{
	qRegisterMetaType<TradeData>("TradeData");
	connect(this, SIGNAL(updateEvent(TradeData)), this, SLOT(updateContent(TradeData)), Qt::QueuedConnection);
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_TRADE, std::bind(&TradeForm::onTrade, this, std::placeholders::_1), "TradeForm");
}

void TradeForm::adjustTableWidget(QTableWidget* tableWidget)
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

void TradeForm::onTrade(Datablk& tr)
{
	TradeData trade = tr.cast<TradeData>();

	emit updateEvent(trade);
}

void TradeForm::updateContent(TradeData trade)
{
	QVariantMap vItem;
	vItem.insert(QStringLiteral("�ɽ����"), codec->toUnicode(trade.tradeID.c_str()));

	vItem.insert(QStringLiteral("ί�б��"), codec->toUnicode(trade.orderID.c_str()));
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(trade.symbol.c_str()));
	vItem.insert(QStringLiteral("����"), codec->toUnicode(trade.direction.c_str()));
	vItem.insert(QStringLiteral("��ƽ"), codec->toUnicode(trade.offset.c_str()));
	vItem.insert(QStringLiteral("�۸�"), trade.price);
	vItem.insert(QStringLiteral("����"), trade.volume);
	vItem.insert(QStringLiteral("�ɽ�ʱ��"), codec->toUnicode(trade.tradeTime.c_str()));
	vItem.insert(QStringLiteral("�ӿ�"), codec->toUnicode(trade.gateWayName.c_str()));


	//����id�ҵ���Ӧ���У�Ȼ�����е�text����map����ȡֵ���õ�item����=
	QString id = vItem.value(QStringLiteral("�ɽ����")).toString();
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

			ui->tradeTableWidget->item(row, i)->setText(str_val);

			//QTableWidgetItem* item = new QTableWidgetItem(str_val);
			//ui->tickTable->setItem(row, i, item);
		}
	}
	else
	{
		int row = table_row_.size();
		ui->tradeTableWidget->insertRow(row);
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
			ui->tradeTableWidget->setItem(row, i, item);
		}
	}

	ui->tradeTableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}