#pragma once
#ifndef __ctplogin_h__
#define __ctplogin_h__
#include <QDialog>

namespace Ui {
	class CtpLogin;
}

class CtpLogin : public QDialog
{
	Q_OBJECT

public:
	CtpLogin(QWidget *parent);
	~CtpLogin();

	QString getPassword();
	QString getUserName();

private:
	Ui::CtpLogin* ui;
};

#endif
