#include "stockball.h"
#include "StockEntity.h"
#include <QtWidgets/QApplication>
#include "qcoreapplication.h"
#include <QTextCodec>  
#include "qfile.h"
#include "Favorite.h"

#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QProgressDialog>
#include <QDebug>
#include <QStringListModel>
#include <QListView>
#include <QListWidget>
#include <QLabel>
#include <QStandardItem>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CStockManager::instance()->loadData();
	StockBall w;
	w.show();

	Favorite e;
	e.show();

	return a.exec();
}
