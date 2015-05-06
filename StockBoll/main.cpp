#include "stockboll.h"
#include <QtWidgets/QApplication>
#include "qcoreapplication.h"
#include <QTextCodec>  
#include "qfile.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFile qss(":/qss/default");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();
	StockBoll w;
	w.show();
	return a.exec();
}
