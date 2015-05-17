#include "system_tray.h"

SystemTray::SystemTray(QWidget *parent)
	: QSystemTrayIcon(parent)
{
	this->createAction();
	this->createTopAction();
	this->createBottomAction();
	this->addActions();
}

SystemTray::~SystemTray()
{

}

void SystemTray::createTopAction()
{
	top_widget = new QWidget();
	protect_label = new QLabel();
    open_button = new QPushButton();
    enter_button = new QPushButton();

	protect_label->setObjectName("whiteLabel");
	open_button->setObjectName("trayButton");
	enter_button->setObjectName("trayButton");

	open_button->setCursor(Qt::PointingHandCursor);
	enter_button->setCursor(Qt::PointingHandCursor);

	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(open_button);
	layout->addStretch();
	layout->addWidget(enter_button);
	layout->setSpacing(0);
	layout->setContentsMargins(0, 0, 0, 0);

	QVBoxLayout *v_layout = new QVBoxLayout();
	v_layout->addWidget(protect_label);
	v_layout->addLayout(layout);
	v_layout->setSpacing(10);
	v_layout->setContentsMargins(10, 5, 10, 5);
	top_widget->setLayout(v_layout);

	top_widget->installEventFilter(this);
}

void SystemTray::createBottomAction()
{
	bottom_widget = new QWidget();
    game_mode_button = new QPushButton();
    online_mode_button = new QPushButton();

	game_mode_button->setObjectName("trayButton");
	online_mode_button->setObjectName("trayButton");

	game_mode_button->setCursor(Qt::PointingHandCursor);
	online_mode_button->setCursor(Qt::PointingHandCursor);

	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget(game_mode_button);
	layout->addStretch();
	layout->addWidget(online_mode_button);
	layout->setSpacing(0);
	layout->setContentsMargins(10, 5, 10, 5);

	bottom_widget->setLayout(layout);

	bottom_widget->installEventFilter(this);
}

void SystemTray::createAction()
{
	this->setIcon(QIcon(":/icon/logo"));

	tray_menu = new QMenu();
	action_open = new QAction(this);
	action_help_center = new QAction(this);
	action_login = new QAction(this);
	action_separate = new QAction(this);
	action_logout = new QAction(this);

	tray_menu->setFixedWidth(250);

	connect(action_open, SIGNAL(triggered()), this, SIGNAL(showWidget()));
	connect(action_logout, SIGNAL(triggered()), qApp, SLOT(quit()));

	this->setContextMenu(tray_menu);
}

void SystemTray::addActions()
{
	//Ìí¼Ó²Ëµ¥Ïî
	tray_menu->addAction(action_open);
	tray_menu->addAction(action_help_center);
	tray_menu->addSeparator();
	tray_menu->addAction(action_login);
	tray_menu->addAction(action_separate);
	tray_menu->addAction(action_logout);
}

bool SystemTray::eventFilter(QObject *obj, QEvent *event)
{
	if(obj == top_widget || obj == bottom_widget)
	{
		if(event->type() == QEvent::Paint)
		{
			QPainter top_painter(top_widget);
			top_painter.setPen(Qt::NoPen);
			top_painter.setBrush(QColor(70, 180, 20));
			top_painter.drawRect(top_widget->rect());	

			QPainter bottom_painter(bottom_widget);
			bottom_painter.setPen(Qt::NoPen);
			bottom_painter.setBrush(QColor(70, 180, 20));
			bottom_painter.drawRect(bottom_widget->rect());	
		}
	}

	return QSystemTrayIcon::eventFilter(obj, event);
}