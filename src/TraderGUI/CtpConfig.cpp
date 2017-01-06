#include "ui_CtpConfig.h"
#include "CtpConfig.h"

#include "utils/ckdef.h"

#include <QFile>
#include <QJsonDocument> 
#include <QJsonObject>

#define CTP_CONFIG_FILE "ctp_setting.json"

CtpConfig::CtpConfig(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::CtpConfig)
{
	ui->setupUi(this);
	setWindowTitle("CTP Config");
	setWindowFlags(windowFlags() &~Qt::WindowCloseButtonHint);

	connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

CtpConfig::~CtpConfig()
{
	delete ui;
}

void CtpConfig::load()
{	
	QFile file(CTP_CONFIG_FILE);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	QByteArray data = file.readAll();

	file.close();

	QJsonParseError json_error;
	QJsonDocument json = QJsonDocument::fromJson(data,&json_error);
	if (json_error.error == QJsonParseError::NoError)
	{
		if (json.isObject())
		{
			QJsonObject obj = json.object();
			if (obj.contains("brokerID"))
			{
				QJsonValue broker = obj.take("brokerID");
				if (broker.isString())
				{
					brokerID = broker.toString();
					ui->brokerIDLineEdit->setText(brokerID);
				}
			}

			if (obj.contains("mdAddress"))
			{
				QJsonValue mdAddress = obj.take("mdAddress");
				if (mdAddress.isString())
				{
					frontMD = mdAddress.toString();
					if (!frontMD.trimmed().toLower().startsWith("tcp://"))
					{
						frontMD = QString("tcp://") + frontMD.trimmed().toLower();
					}
					else 
					{
						frontMD = frontMD.trimmed().toLower();
					}
					ui->mdAddressLineEdit->setText(frontMD);
				}
			}

			if (obj.contains("tdAddress"))
			{
				QJsonValue tdAddress = obj.take("tdAddress");
				if (tdAddress.isString())
				{
					frontTD = tdAddress.toString();
					if (!frontTD.trimmed().toLower().startsWith("tcp://"))
					{
						frontTD = QString("tcp://") + frontTD.trimmed().toLower();
					}
					else
					{
						frontTD = frontTD.trimmed().toLower();
					}
					ui->tdAddressLineEdit->setText(frontTD);
				}
			}
		}
	}
}

void CtpConfig::save()
{
	QJsonObject json;
		
	QString broker = ui->brokerIDLineEdit->text();
	if (!broker.isEmpty())
	{
		brokerID = broker;
	}

	QString mdAddress = ui->mdAddressLineEdit->text();
	if (!mdAddress.isEmpty())
	{
		frontMD = mdAddress;
	}

	QString tdAddress = ui->tdAddressLineEdit->text();
	if (!tdAddress.isEmpty())
	{
		frontTD = tdAddress;
	}

	json.insert("brokerID", brokerID);
	json.insert("mdAddress", frontMD);
	json.insert("tdAddress", frontTD);

	QJsonDocument document;
	document.setObject(json);
	QByteArray byte_array = document.toJson(QJsonDocument::Compact);

	QFile file(CTP_CONFIG_FILE);
	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	file.write(byte_array);

	file.close();
}