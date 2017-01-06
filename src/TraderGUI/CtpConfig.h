#pragma once
#ifndef __ctpconfig_h__
#define __ctpconfig_h__

#include <QDialog>

namespace Ui {
	class CtpConfig;
}

class CtpConfig : public QDialog
{
	Q_OBJECT

public:
	CtpConfig(QWidget *parent);
	~CtpConfig();

	void load();
	void save();

private:
	Ui::CtpConfig* ui;

	QString brokerID;
	QString frontMD;
	QString frontTD;

};

#endif
