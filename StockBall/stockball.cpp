#include "StockBall.h"
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

	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->setColumnStretch(0, 1);
	gridLayout->setColumnStretch(1, 1);

	gridLayout->setMargin(15);
	gridLayout->setColumnStretch(0, 1);
	gridLayout->setColumnStretch(1, 1);

	QLabel *lbl1 = new QLabel(QWidget::tr("1"));
	lbl1->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
	QLabel *lbl2 = new QLabel(QWidget::tr("2"));
	lbl2->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
	QLabel *lbl3 = new QLabel(QWidget::tr("3"));
	lbl3->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
	QLabel *lbl4 = new QLabel(QWidget::tr("4"));
	lbl4->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);

	gridLayout->addWidget(lbl1, 0, 0);
	gridLayout->addWidget(lbl2, 0, 1);
	gridLayout->addWidget(lbl3, 1, 0);
	gridLayout->addWidget(lbl4, 1, 1);

	setLayout(gridLayout);

	resize(100, 100);
	setWindowTitle(QWidget::tr("Qt Test"));

	setWindowFlags(Qt::FramelessWindowHint);
	//setAttribute(Qt::WA_TranslucentBackground);//设置背景透明
	QPixmap pix;
	pix.load(":/images/360bg");  //第三个参数为读取图片的方式
	//resize(pix.size());
	mouseMovePos = QPoint(0, 0);


	m_nTimerId = startTimer(1000);
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
}

void StockBall::timerEvent(QTimerEvent *event)
{
	network_manager = new QNetworkAccessManager(this);
	connect(network_manager, SIGNAL(finished(QNetworkReply*)),
		this, SLOT(replyFinished(QNetworkReply*)));
	QUrl url;
	url.setUrl("http://hq.sinajs.cn/list=sh601006");
	QNetworkRequest network_request;
	network_request.setUrl(url);
	network_manager->get(network_request);
}

void StockBall::replyFinished(QNetworkReply *reply)  //当回复结束后  
{
	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QString all = codec->toUnicode(reply->readAll());
	reply->deleteLater();
}
