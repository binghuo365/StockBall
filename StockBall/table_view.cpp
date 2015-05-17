#include "table_view.h"
#include "QPainter"
#include "QPalette"
#include "QStandardItemModel"
#include "QHeaderView"

TableView::TableView(QWidget *parent /*= 0*/) : QTableView(parent)
{
	setMinimumSize(270, 570);
	setFrameShape(QFrame::NoFrame);
	init();
}

void TableView::paintEvent(QPaintEvent *e)
{

}

TableView::~TableView()
{

}

void TableView::init()
{
	QStandardItemModel *student_model = new QStandardItemModel();
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
	//horizontalHeader()->hide();

	for (int i = 0; i < 20; ++i)
	{
		student_model->setItem(i, 0, new QStandardItem("name"));
		student_model->setItem(i, 1, new QStandardItem("value"));
		student_model->setItem(i, 2, new QStandardItem("change"));
		student_model->setItem(i, 3, new QStandardItem("percent"));

		student_model->item(i, 0)->setTextAlignment(Qt::AlignCenter);
		student_model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
		student_model->item(i, 2)->setTextAlignment(Qt::AlignCenter);
		student_model->item(i, 3)->setTextAlignment(Qt::AlignCenter);
		//设置单元格文本颜色，张三的数据设置为红色
		student_model->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 1)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 2)->setForeground(QBrush(QColor(255, 0, 0)));
		student_model->item(i, 3)->setForeground(QBrush(QColor(255, 0, 0)));
		//将字体加粗
		student_model->item(i, 0)->setFont(QFont("Times", 10, QFont::Black));
		student_model->item(i, 1)->setFont(QFont("Times", 10, QFont::Black));
		student_model->item(i, 2)->setFont(QFont("Times", 10, QFont::Black));
		student_model->item(i, 3)->setFont(QFont("Times", 10, QFont::Black));
	}
}

