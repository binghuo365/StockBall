#include "table_view.h"
#include "QPainter"
#include "QPalette"
#include "QStandardItemModel"
#include "QHeaderView"
#include "qabstractscrollarea.h"
#include "qfile.h"
#include "QScrollBar"
#include "QMessageBox"
#include "StockEntity.h"

TableView::TableView(QWidget *parent /*= 0*/) : QTableView(parent), WrTimer()
{
	setMinimumSize(270, 560);
	setFrameShape(QFrame::NoFrame);

	WrTimer = new QTimer(this);
	connect(WrTimer, SIGNAL(timeout()), this, SLOT(init()), Qt::DirectConnection);
	WrTimer->start(1000);

	verticalScrollBar()->setStyleSheet("QScrollBar:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;"
		"padding-top:9px;"
		"padding-bottom:9px;"
		"}"
		"QScrollBar::handle:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,25%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::handle:vertical:hover"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,50%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::add-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a_3.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a_1.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a_4.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/images/a_2.png);"
		"subcontrol-position:top;"
		"}"

		"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
		"{"
		"background:rgba(0,0,0,10%);"
		"border-radius:4px;"
		"}"
		);
}

void TableView::paintEvent(QPaintEvent *e)
{
	QTableView::paintEvent(e);
}

TableView::~TableView()
{

}

void TableView::init()
{
	QStandardItemModel *student_model = new QStandardItemModel();
	student_model->setColumnCount(4);    // 设置列数
	student_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
	student_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("Value")));
	student_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Change")));
	student_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Percent")));
	//利用setModel()方法将数据模型与QTableView绑定
	setModel(student_model);
	setColumnWidth(0, 60);
	setColumnWidth(1, 70);
	setColumnWidth(2, 62);
	setColumnWidth(3, 61);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	verticalHeader()->hide();
	horizontalHeader()->hide();
	setShowGrid(false);
	setStyleSheet("border:none;");

	const std::map<QString, CEntity*>& map = CStockManager::instance()->getFavirateEntity();
	int i = 0;
	for (std::map<QString, CEntity*>::const_iterator it = map.begin(); it != map.end(); ++it, ++i)
	{
		QString temp;
		student_model->setItem(i, 0, new QStandardItem(QString::fromUtf8(it->second->name.toLocal8Bit())));
		temp.sprintf("%0.2lf", it->second->value);
		student_model->setItem(i, 1, new QStandardItem(temp));
		temp.sprintf("%0.2lf", it->second->change);
		student_model->setItem(i, 2, new QStandardItem(temp));
		temp.sprintf("%0.2lf%%", it->second->percent);
		student_model->setItem(i, 3, new QStandardItem(temp));
		setRowHeight(i, 25);

		student_model->item(i, 0)->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
		student_model->item(i, 1)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		student_model->item(i, 2)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		student_model->item(i, 3)->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);

		student_model->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 1)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 2)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 3)->setForeground(QBrush(QColor(255, 0, 0)));

	}
}

