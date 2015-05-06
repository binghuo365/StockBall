#ifndef STOCKBOLL_H
#define STOCKBOLL_H

#include <QtWidgets/QWidget>
#include "ui_stockboll.h"
#include <QSystemTrayIcon>
#include "qaction.h"
#include "qbitmap.h"
#include "QNetworkReply"

class StockBoll : public QWidget
{
	Q_OBJECT

public:
	StockBoll(QWidget *parent = 0);
	~StockBoll();

protected:
	virtual void  mouseMoveEvent(QMouseEvent *event);
	virtual void  mousePressEvent(QMouseEvent *event);
	virtual void  mouseReleaseEvent(QMouseEvent *event);
	virtual void  paintEvent(QPaintEvent *);
	virtual void  timerEvent(QTimerEvent *event);

public:
	void replyFinished(QNetworkReply *reply);
	void on_readyRead();

private:
	Ui::StockBollClass ui;
	QPoint mouseMovePos;
	QSystemTrayIcon *trayIcon;
	QAction *minimizeAction;
	QAction *restoreAction;
	QAction *quitAction;
	QMenu   *trayIconMenu;
	int m_nTimerId;
	QNetworkAccessManager* netManager;

};

#endif // STOCKBOLL_H
