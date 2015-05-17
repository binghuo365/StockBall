#ifndef SYSYTEMTRAY_H
#define SYSYTEMTRAY_H

#include <QWidget>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QApplication>
#include <QWidgetAction>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QPainter>

class SystemTray : public QSystemTrayIcon
{
	Q_OBJECT

public:

	explicit SystemTray(QWidget *parent = 0);
	~SystemTray();

protected:

	bool eventFilter(QObject *obj, QEvent *event);

signals:

	void showWidget();

private:

	void createTopAction();
	void createBottomAction();
	void createAction();
	void addActions();

private:

	QMenu *tray_menu; //托盘菜单

	QWidget *top_widget;  //顶部菜单项
	QLabel *protect_label;  //360已保护电脑...天
    QPushButton *open_button;  //木马防火墙已经开启
    QPushButton *enter_button;  //进入
	
	QWidget *bottom_widget;  //底部菜单项
    QPushButton *game_mode_button;  //进入游戏模式
    QPushButton *online_mode_button;  //进入网购模式

	QAction *action_open; //打开360安全卫士
	QAction *action_help_center; //求助中心

	QAction *action_login; //360用户登录
	QAction *action_separate; //隔离沙箱
	QAction *action_logout; //退出

};

#endif //SYSYTEMTRAY_H
