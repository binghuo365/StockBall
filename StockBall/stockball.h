#ifndef STOCKBALL_H
#define STOCKBALL_H

#include <QtWidgets/QWidget>
#include "ui_stockball.h"
#include <QSystemTrayIcon>
#include "qaction.h"
#include "qbitmap.h"
#include "QNetworkReply"
#include "SubGetDataThread.h"

class StockBall : public QWidget
{
	Q_OBJECT

public:
	StockBall(QWidget *parent = 0);
	~StockBall();

public:
	void test();

protected:
	virtual void  mouseMoveEvent(QMouseEvent *event);
	virtual void  mousePressEvent(QMouseEvent *event);
	virtual void  mouseReleaseEvent(QMouseEvent *event);
	virtual void enterEvent(QEvent *);
	virtual void leaveEvent(QEvent *);
	virtual void  paintEvent(QPaintEvent *);

public slots:
	void DisplayMsg(int);

private:
	Ui::StockBallClass ui;
	QPoint mouseMovePos;
	QSystemTrayIcon *trayIcon;
	QAction *minimizeAction;
	QAction *restoreAction;
	QAction *quitAction;
	QMenu   *trayIconMenu;

	int m_Result[4];
	QColor m_Color[4];
	QPoint m_CurrentPos;

	SubGetDataThread* t;
};

#endif // STOCKBALL_H
