#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>
#include <QSplitter>
#include <QToolButton>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QPainter>
#include <QPen>
#include <QHBoxLayout>
#include <QEvent>
#include <QVBoxLayout>
#include "table_view.h"

class ContentWidget : public QWidget
{
    Q_OBJECT

public:

    explicit ContentWidget(QWidget *parent = 0);

private:

	void init();

protected:

	bool eventFilter(QObject *obj, QEvent *event);

	void paintEvent(QPaintEvent *event);

signals:

private:
	TableView* tableView;

};

#endif // CONTENTWIDGET_H