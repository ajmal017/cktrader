#include "ui_TickForm.h"
#include "TickForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"
#include "servicemgr_iml.h"

#include <QMessageBox>
#include <QTextCodec>

using namespace cktrader;

TickForm::TickForm(cktrader::ServiceMgr* serviceMgr,QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::TickForm)
{
	this->serviceMgr = serviceMgr;
	ui->setupUi(this);

	codec = QTextCodec::codecForName("gbk");

	this->ui->tickTable->clearContents();
	this->ui->tickTable->setSortingEnabled(false);

	//������=
	table_col_ << QStringLiteral("��Լ����")
		<< QStringLiteral("��Լ����")
		<< QStringLiteral("���¼�")

		<< QStringLiteral("�ɽ���")

		<< QStringLiteral("��һ��")
		<< QStringLiteral("��һ��")
		<< QStringLiteral("��һ��")
		<< QStringLiteral("��һ��")

		<< QStringLiteral("�ֲ���")
		<< QStringLiteral("���̼�")
		<< QStringLiteral("��߼�")
		<< QStringLiteral("��ͼ�")
		
		<< QStringLiteral("ʱ��")

		<< QStringLiteral("��ͣ��")
		<< QStringLiteral("��ͣ��")
		<< QStringLiteral("�ӿ�");

	this->ui->tickTable->setColumnCount(table_col_.length());
	for (int i = 0; i < table_col_.length(); i++)
	{
		ui->tickTable->setHorizontalHeaderItem(i, new QTableWidgetItem(table_col_.at(i)));
	}

	adjustTableWidget(ui->tickTable);

	table_row_.clear();
}

TickForm::~TickForm()
{
	delete ui;
}

void TickForm::init()
{
	this->serviceMgr->getEventEngine()->registerHandler(EVENT_TICK, std::bind(&TickForm::onTick, this, std::placeholders::_1), "TickForm");
	connect(ui->tickTable, SIGNAL(cellClicked(int, int)), this, SLOT(tableWidget_cellClicked(int, int)));
	connect(ui->orderPushButton,SIGNAL(clicked()), this, SLOT(pushButtonSendOrder_clicked()));
	connect(ui->contractLineEdit, SIGNAL(returnPressed()), this, SLOT(contractlineedit_returnPressed()));
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

	QVariantMap vItem;
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(tick_data.symbol.c_str()));
	// tick�����exchange��һ����=
	ContractData contract;
	serviceMgr->getContract(tick_data.symbol, contract);
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(contract.name.c_str()));
	vItem.insert(QStringLiteral("���¼�"), tick_data.lastPrice);
	vItem.insert(QStringLiteral("�ɽ���"), tick_data.volume);
	vItem.insert(QStringLiteral("��һ��"), tick_data.bidPrice1);
	vItem.insert(QStringLiteral("��һ��"), tick_data.bidVolume1);
	vItem.insert(QStringLiteral("��һ��"), tick_data.askPrice1);
	vItem.insert(QStringLiteral("��һ��"), tick_data.askVolume1);
	vItem.insert(QStringLiteral("�ֲ���"), tick_data.openInterest);
	vItem.insert(QStringLiteral("���̼�"), tick_data.openPrice);
	vItem.insert(QStringLiteral("��߼�"), tick_data.highPrice);
	vItem.insert(QStringLiteral("��ͼ�"), tick_data.lowPrice);
	vItem.insert(QStringLiteral("ʱ��"), codec->toUnicode(tick_data.time.c_str()));
	vItem.insert(QStringLiteral("��ͣ��"), tick_data.upperLimit);
	vItem.insert(QStringLiteral("��ͣ��"), tick_data.lowerLimit);
	vItem.insert(QStringLiteral("�ӿ�"), codec->toUnicode(tick_data.gateWayName.c_str()));

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
			ui->tickTable->setItem(row, i, item);
		}
	}
	else
	{
		int row = table_row_.size();
		ui->tickTable->insertRow(row);
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
			ui->tickTable->setItem(row, i, item);
		}
	}
	
}

void TickForm::pushButtonSendOrder_clicked()
{
	QString symbol = ui->contractLineEdit->text();
	double price = ui->priceDoubleSpinBox->value();
	double volume = ui->volDoubleSpinBox->value();

	QString priceType = ui->priceTypeComboBox->currentData().toString();
	QString direction = ui->directionComboBox->currentData().toString();
	QString offset = ui->offsetComboBox->currentData().toString();
	QString currency = ui->currencyComboBox->currentData().toString();

	OrderReq req;
	req.symbol = symbol.toStdString();
	ContractData cn;
	serviceMgr->getContract(req.symbol, cn);

	req.exchange = cn.exchange;
	req.price = price;
	req.volume = volume;
	req.priceType = priceType.toStdString();
	req.direction = offset.toStdString();
	req.currency = currency.toStdString();

	IGateway* pGateway = serviceMgr->getGateWay(cn.gateWayName);

	if (pGateway)
	{
		pGateway->sendOrder(req);
	}
	else
	{
		QStringList x;
		x << cn.gateWayName.c_str()
			<< QStringLiteral("�����ڣ���ȷ���Ƿ��¼");

		QMessageBox::critical(this, QStringLiteral("δ�ҵ�Gateway"),x.join(","));
	}
}

void TickForm::tableWidget_cellClicked(int row, int column)
{
	(void)column;

	QString symbol = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("��Լ����")))->text();
	auto item = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("���¼�")));
	double lastPrice = item ? item->text().toDouble() : 0.0;
	item = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("��ͣ��")));
	double upperLimit = item ? item->text().toDouble() : 0.0;
	item = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("��ͣ��")));
	double lowerLimit = item ? item->text().toDouble() : 0.0;

	ui->contractLineEdit->setText(symbol);

	//����price
	ui->priceDoubleSpinBox->setValue(lastPrice);
	ui->priceDoubleSpinBox->setMaximum(upperLimit);
	ui->priceDoubleSpinBox->setMinimum(lowerLimit);

	ContractData cn;
	bool havecontract = serviceMgr->getContract(symbol.toStdString(), cn);

	if (havecontract) 
	{
		ui->priceDoubleSpinBox->setSingleStep(cn.priceTick);
	}
}

void  TickForm::contractlineedit_returnPressed()
{
	QString symbol = ui->contractLineEdit->text();

	ContractData cn;
	bool havecontract = serviceMgr->getContract(symbol.toStdString(), cn);

	if (havecontract)
	{
		IGateway* pGateway = serviceMgr->getGateWay(cn.gateWayName);
		SubscribeReq req;
		req.symbol = symbol.toStdString();
		pGateway->subscribe(req);
	}
	else
	{
		QMessageBox::warning(this, QStringLiteral("����"), QStringLiteral("û�д˺�Լ"));
	}
}