#include "TraderGUI.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <qfile.h>
#include <qtextstream.h>

int main(int argc, char *argv[])
{
	int result = 0;

    QApplication a(argc, argv);
    
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

	TraderGUI w;
	w.init();
	w.move((QApplication::desktop()->width() - w.width()) / 2, (QApplication::desktop()->height() - w.height()) / 3);
	w.show();

	result = a.exec();

	w.shutdown();

	return result;

}
