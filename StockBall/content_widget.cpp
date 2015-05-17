#include "content_widget.h"
#include "table_view.h"

ContentWidget::ContentWidget(QWidget *parent)
: QWidget(parent)
{
	QHBoxLayout *main_layout = new QHBoxLayout();
	tableView = new TableView(this);

	main_layout->addWidget(tableView, 0, Qt::AlignVCenter);
	main_layout->setContentsMargins(0, 0, 0, 0);
	this->setLayout(main_layout);

	this->init();
}

void ContentWidget::init()
{

}

bool ContentWidget::eventFilter(QObject *obj, QEvent *event)
{
	return QWidget::eventFilter(obj, event);
}

void ContentWidget::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawRect(this->rect());
}
