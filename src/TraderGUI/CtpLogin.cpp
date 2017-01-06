#include "CtpLogin.h"
#include "ui_CtpLogin.h"

CtpLogin::CtpLogin(QWidget *parent)
	: QDialog(parent)
	,ui(new Ui::CtpLogin)
{
	ui->setupUi(this);
	setWindowTitle("ctp login");

	connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

CtpLogin::~CtpLogin()
{
	delete ui;
}

QString CtpLogin::getPassword()
{
	return ui->passwordLineEdit->text();
}

QString CtpLogin::getUserName()
{
	return ui->userNameLineEdit->text();
}
