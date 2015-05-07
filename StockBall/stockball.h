#ifndef STOCKBALL_H
#define STOCKBALL_H

#include <QtWidgets/QWidget>
#include "ui_stockball.h"
#include <QSystemTrayIcon>
#include "qaction.h"
#include "qbitmap.h"
#include "QNetworkReply"

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
	virtual void  paintEvent(QPaintEvent *);
	virtual void  timerEvent(QTimerEvent *event);

public slots:
	void replyFinished(QNetworkReply *reply);

private:
	Ui::StockBallClass ui;
	QNetworkAccessManager* network_manager;
	QPoint mouseMovePos;
	QSystemTrayIcon *trayIcon;
	QAction *minimizeAction;
	QAction *restoreAction;
	QAction *quitAction;
	QMenu   *trayIconMenu;
	int m_nTimerId;
};

#endif // STOCKBALL_H
