#include "ui_TickForm.h"
#include "TickForm.h"
#include "NoFocusDelegate.h"
#include "qstring.h"
#include "servicemgr_iml.h"

#include <QMessageBox>
#include <QTextCodec>
#include <QMetaType>

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
	qRegisterMetaType<TickData>("TickData");

	this->serviceMgr->getEventEngine()->registerHandler(EVENT_TICK, std::bind(&TickForm::onTick, this, std::placeholders::_1), "TickForm");
	connect(ui->tickTable, SIGNAL(cellClicked(int, int)), this, SLOT(tableWidget_cellClicked(int, int)), Qt::QueuedConnection);
	connect(ui->orderPushButton,SIGNAL(clicked()), this, SLOT(pushButtonSendOrder_clicked()), Qt::QueuedConnection);
	connect(ui->contractLineEdit, SIGNAL(returnPressed()), this, SLOT(contractlineedit_returnPressed()), Qt::QueuedConnection);
	connect(this, SIGNAL(updateEvent(TickData)), this, SLOT(updateContent(TickData)), Qt::QueuedConnection);
}

void TickForm::adjustTableWidget(QTableWidget* tableWidget)
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

void TickForm::onTick(Datablk& tick)
{
	TickData tick_data = tick.cast<TickData>();

	emit updateEvent(tick_data);
}

void TickForm::pushButtonSendOrder_clicked()
{
	QString symbol = ui->contractLineEdit->text();
	double price = ui->priceDoubleSpinBox->value();
	double volume = ui->volDoubleSpinBox->value();

	QString priceType = ui->priceTypeComboBox->currentText();
	QString direction = ui->directionComboBox->currentText();
	QString offset = ui->offsetComboBox->currentText();
	QString currency = ui->currencyComboBox->currentText();

	OrderReq req;
	req.symbol = symbol.toLocal8Bit().toStdString();

	ContractData cn;
	serviceMgr->getContract(req.symbol, cn);
	req.exchange = cn.exchange;

	req.price = price;
	req.volume = volume;
	//req.priceType = priceType.toStdString();
	req.priceType = priceType.toLocal8Bit().toStdString();
	req.direction = direction.toLocal8Bit().toStdString();
	req.offset = offset.toLocal8Bit().toStdString();
	req.currency = currency.toLocal8Bit().toStdString();

	IGateway* pGateway = serviceMgr->getGateWay(cn.gateWayName);

	if (pGateway)
	{
		pGateway->sendOrder(req);
	}
	else
	{
		QStringList x;
		x << QStringLiteral("��Լ�����ڣ���ȷ���Ƿ��ȡ�˺�Լ");

		QMessageBox::critical(this, QStringLiteral("δ�ҵ�Gateway"),x.join(","));
	}
}

void TickForm::tableWidget_cellClicked(int row, int column)
{
	(void)column;

	QString symbol = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("��Լ����")))->text();
	auto itemPrice = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("���¼�")));
	double lastPrice = itemPrice ? itemPrice->text().toDouble() : 0.0;
	auto itemUper = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("��ͣ��")));
	double upperLimit = itemUper ? itemUper->text().toDouble() : 0.0;
	auto itemLower = ui->tickTable->item(row, table_col_.indexOf(QStringLiteral("��ͣ��")));
	double lowerLimit = itemLower ? itemLower->text().toDouble() : 0.0;

	ui->contractLineEdit->setText(symbol);

	//����price	
	ui->priceDoubleSpinBox->setMaximum(upperLimit);
	ui->priceDoubleSpinBox->setMinimum(lowerLimit);
	ui->priceDoubleSpinBox->setValue(lastPrice);

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

void TickForm::updateContent(TickData tick)
{
	QVariantMap vItem;
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(tick.symbol.c_str()));
	// tick�����exchange��һ����=
	ContractData contract;
	serviceMgr->getContract(tick.symbol, contract);
	vItem.insert(QStringLiteral("��Լ����"), codec->toUnicode(contract.name.c_str()));

	//����tick���ݣ���ֹ���ִ�������Ҫ�ж�
	if (tick.lastPrice == DBL_MAX)
	{
		vItem.insert(QStringLiteral("���¼�"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("���¼�"), tick.lastPrice);
	}	
	vItem.insert(QStringLiteral("�ɽ���"), tick.volume);

	if (tick.bidPrice1 == DBL_MAX)
	{
		vItem.insert(QStringLiteral("��һ��"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("��һ��"),tick.bidPrice1);
	}	
	vItem.insert(QStringLiteral("��һ��"), tick.bidVolume1);

	if (tick.askPrice1 == DBL_MAX)
	{
		vItem.insert(QStringLiteral("��һ��"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("��һ��"), tick.askPrice1);
	}	
	vItem.insert(QStringLiteral("��һ��"), tick.askVolume1);
	vItem.insert(QStringLiteral("�ֲ���"), tick.openInterest);

	if (tick.openPrice == DBL_MAX)
	{
		vItem.insert(QStringLiteral("���̼�"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("���̼�"), tick.openPrice);
	}

	if (tick.highPrice == DBL_MAX)
	{
		vItem.insert(QStringLiteral("��߼�"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("��߼�"), tick.highPrice);
	}

	if (tick.lowPrice == DBL_MAX)
	{
		vItem.insert(QStringLiteral("��ͼ�"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("��ͼ�"), tick.lowPrice);
	}	
	
	vItem.insert(QStringLiteral("ʱ��"), codec->toUnicode(tick.time.c_str()));

	if (tick.upperLimit == DBL_MAX)
	{
		vItem.insert(QStringLiteral("��ͣ��"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("��ͣ��"), tick.upperLimit);
	}

	if (tick.lowerLimit == DBL_MAX)
	{
		vItem.insert(QStringLiteral("��ͣ��"), 0.0);
	}
	else
	{
		vItem.insert(QStringLiteral("��ͣ��"), tick.lowerLimit);
	}	
	
	vItem.insert(QStringLiteral("�ӿ�"), codec->toUnicode(tick.gateWayName.c_str()));

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

			ui->tickTable->item(row, i)->setText(str_val);

			//QTableWidgetItem* item = new QTableWidgetItem(str_val);
			//ui->tickTable->setItem(row, i, item);
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

	ui->tickTable->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}