#include "stockball.h"
#include "StockEntity.h"
#include <QtWidgets/QApplication>
#include "qcoreapplication.h"
#include <QTextCodec>  
#include "qfile.h"
#include "Favorite.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFile qss(":/qss/default");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();

	//¼ÓÔØdata
	//CStockManager::instance()->loadData();
	//StockBall w;
	//w.show();
	//return a.exec();

	Favorite e;
	e.show();
	return e.exec();
}
