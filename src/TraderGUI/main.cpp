#include "TraderGUI.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <qfile.h>
#include <qtextstream.h>
#include <QTextCodec>

#include "servicemgr_iml.h"

using namespace cktrader;

int main(int argc, char *argv[])
{
	int result = 0;

    QApplication a(argc, argv);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));
    
	/*QFile f("./qdarkstyle/style.qss");
	if (!f.exists())
	{
		printf("Unable to set stylesheet, file not found\n");
	}
	else
	{
		f.open(QFile::ReadOnly | QFile::Text);
		QTextStream ts(&f);
		a.setStyleSheet(ts.readAll());
	}*/
	ServiceMgr service;

	TraderGUI w(&service);
	w.init();
	w.move((QApplication::desktop()->width() - w.width()) / 2, (QApplication::desktop()->height() - w.height()) / 3);
	//w.show();
	w.showMaximized();

	result = a.exec();

	return result;

}
