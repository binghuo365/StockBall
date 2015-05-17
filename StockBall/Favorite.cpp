#include "Favorite.h"

Favorite::Favorite(QWidget *parent)
: DropShadowWidget(parent)
{
	initLocalConnection();
	setMinimumSize(270, 600);
	setWindowIcon(QIcon(":/icon/logo"));

	title_widget = new TitleWidget();
	content_widget = new ContentWidget();
	system_tray = new SystemTray(this);

	QVBoxLayout *main_layout = new QVBoxLayout();
	main_layout->addWidget(title_widget);
	main_layout->addWidget(content_widget);
	main_layout->setSpacing(0);
	main_layout->setContentsMargins(SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH, SHADOW_WIDTH);
	setLayout(main_layout);

	connect(title_widget, SIGNAL(showMin()), this, SLOT(showMinimized()));
	connect(title_widget, SIGNAL(closeWidget()), this, SLOT(hide()));

	connect(system_tray, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconIsActived(QSystemTrayIcon::ActivationReason)));
	connect(system_tray, SIGNAL(showWidget()), this, SLOT(showWidget()));

	system_tray->show();
}

Favorite::~Favorite()
{

}

void Favorite::initLocalConnection()
{
	is_running = false;
}

bool Favorite::isRunning()
{
	return is_running;
}

void Favorite::paintEvent(QPaintEvent *event)
{
	DropShadowWidget::paintEvent(event);
	QPainter painter(this);
	painter.setPen(Qt::NoPen);
	painter.setBrush(Qt::white);
	painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width() - 2 * SHADOW_WIDTH, this->height() - 2 * SHADOW_WIDTH), QPixmap(":/images/360bg"));
}

void Favorite::iconIsActived(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
		//点击托盘图标之后松开
	case QSystemTrayIcon::Trigger:
	case QSystemTrayIcon::DoubleClick:
	{
		showWidget();
		break;
	}
	default:
		break;
	}
}

void Favorite::showWidget()
{
	this->showNormal();
	this->raise();
	this->activateWindow();
}
