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
	QIcon icon = QIcon(":/icon/logo");
	trayIcon = new QSystemTrayIcon(this);
	trayIcon->setIcon(icon);
	trayIcon->setToolTip(tr("hello"));
	QString titlec = tr("title");
	QString textc = tr("hell0:text");
	trayIcon->show();
	trayIcon->showMessage(titlec, textc, QSystemTrayIcon::Information, 2000);


	ui.setupUi(this);
	m_Color[0] = Qt::red;
	m_Color[1] = Qt::yellow;
	m_Color[2] = Qt::green;
	m_Color[3] = Qt::blue;
	memset(m_Result, 1, sizeof(m_Result));

	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
	setAttribute(Qt::WA_TranslucentBackground);//���ñ���͸��
	//QPixmap pix;
	//pix.load(":/images/360bg");  //����������Ϊ��ȡͼƬ�ķ�ʽ
	//resize(pix.size());

	resize(50, 50);
	setWindowOpacity(0.5);
	mouseMovePos = QPoint(0, 0);
	m_nTimerId = startTimer(3000);

	t = new SubGetDataThread();
	connect(t, SIGNAL(Signal(int)), this, SLOT(DisplayMsg(int)));
	//ִ�����߳�
	t->start();
}

void StockBall::DisplayMsg(int msg)
{
	QString temp;
	temp.sprintf("%d", msg);
	QMessageBox::about(NULL, "title", temp);
}

StockBall::~StockBall()
{
	if (m_nTimerId != 0)
	{
		killTimer(m_nTimerId);
	}
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
	//painter.drawPixmap(0, 0, QPixmap(":/images/360bg"));
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
	//�����û��Ͷ��Ʊ���Ǿ��Ȼ�һ����ɫ��Բ��  
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

		//����������Ӧ������  
		double abc = 3.14 * 2 * (double)(pos + angle / 2) / FULL_CIRCLE;
		double tx =  qCos(abc) + 10 + RADIUS;
		double ty = -1 * qSin(abc) + 10 + RADIUS;
		painter.drawPie(rect, pos, angle);
		//��������дע�ͣ�ͶƱ���Ͱٷֱȣ�  
		QString temp;
		temp.sprintf("%0.1lf%%", persent * 100);
		painter.drawText(25, 25, temp);
		pos += angle;
	}
}

void StockBall::timerEvent(QTimerEvent *event)
{

}

void StockBall::enterEvent(QEvent *)
{
	//������ڴ�����ʱ��һ����ָ      
	setCursor(Qt::PointingHandCursor);
	setWindowOpacity(1);
}

void StockBall::leaveEvent(QEvent *)
{
	//����뿪����ʱ����ͨ��ָ��      
	setCursor(Qt::ArrowCursor);
	setWindowOpacity(0.5);
}