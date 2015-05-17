#include "StockBall.h"
#include <QtGui>  
#include "qcursor.h"
#include "qevent.h"
#include "qabstractitemdelegate.h"
#include "qpainter.h"
#include "QGridLayout"
#include "QLabel"
#include "QNetworkAccessManager"
#include "QNetworkRequest"
#include "QTextCodec"
#include "QNetworkReply"
#include "QMessageBox"
#include <QtCore/qmath.h>  

StockBall::StockBall(QWidget *parent)
	: QWidget(parent)
{
	setWindowIcon(QIcon(":/icon/logo"));
	system_tray = new SystemTray(this);
	ui.setupUi(this);
	m_Color[0] = Qt::red;
	m_Color[1] = Qt::yellow;
	m_Color[2] = Qt::green;
	m_Color[3] = Qt::blue;
	memset(m_Result, 1, sizeof(m_Result));

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground);//设置背景透明

	resize(50, 50);
	setWindowOpacity(0.5);
	mouseMovePos = QPoint(0, 0);
	connect(system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
	connect(system_tray, SIGNAL(showWidget()), this, SLOT(showWidget()));

	system_tray->show();
	//t = new SubGetDataThread();
	//connect(t, SIGNAL(Signal(int)), this, SLOT(DisplayMsg(int)));
	//执行子线程
	//t->start();
}

void StockBall::DisplayMsg(int msg)
{
	QString temp;
	temp.sprintf("%d", msg);
	QMessageBox::about(NULL, "title", temp);
}

StockBall::~StockBall()
{

}

void StockBall::mouseMoveEvent(QMouseEvent *event)
{
	if (mouseMovePos != QPoint(0, 0))
	{
		move(geometry().x() + event->globalPos().x() - mouseMovePos.x(), geometry().y() + event->globalPos().y() - mouseMovePos.y());
		mouseMovePos = event->globalPos();
	}
}

void StockBall::mousePressEvent(QMouseEvent *event)
{
	mouseMovePos = event->globalPos();
}

void StockBall::mouseReleaseEvent(QMouseEvent *event)
{
	mouseMovePos = QPoint(0, 0);
}

void StockBall::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing, true);
	int cy = 10;
	painter.setPen(QPen(Qt::white, 1));
	const int FULL_CIRCLE = 5760;
	const int RADIUS = 50;
	QRect rect(0, 0, this->width(), this->height());
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		count += m_Result[i];
	}
	//如果还没有投过票，那就先画一个白色的圆形  
	if (0 == count)
	{
		painter.setBrush(Qt::white);
		painter.drawEllipse(rect);
		return;
	}

	int pos = 0;
	int angle;
	for (int i = 0; i < 4; i++)
	{
		if (0 == m_Result[i])
			continue;
		painter.setBrush(m_Color[i]);
		double persent = (double)m_Result[i] / count;
		angle = FULL_CIRCLE * persent;

		//画出各个对应的扇形  
		double abc = 3.14 * 2 * (double)(pos + angle / 2) / FULL_CIRCLE;
		double tx =  qCos(abc) + 10 + RADIUS;
		double ty = -1 * qSin(abc) + 10 + RADIUS;
		painter.drawPie(rect, pos, angle);
		//在扇形上写注释（投票数和百分比）  
		QString temp;
		temp.sprintf("%0.1lf%%", persent * 100);
		painter.drawText(25, 25, temp);
		pos += angle;
	}
}

void StockBall::enterEvent(QEvent *)
{
	//鼠标留在窗口上时是一个手指      
	setCursor(Qt::PointingHandCursor);
	setWindowOpacity(1);
}

void StockBall::leaveEvent(QEvent *)
{
	//鼠标离开窗口时是普通的指针      
	setCursor(Qt::ArrowCursor);
	setWindowOpacity(0.5);
}

void StockBall::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
			//点击托盘图标之后松开
		case QSystemTrayIcon::Trigger:
			//双击托盘图标
		case QSystemTrayIcon::DoubleClick:
		{
											 this->showNormal();
											 this->raise();
											 this->activateWindow();
		}
		default:
			break;
	}
}
