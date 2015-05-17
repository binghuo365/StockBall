#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDesktopWidget>
#include <QTranslator>
#include <QLocalSocket>
#include <QLocalServer>
#include "system_tray.h"
#include "title_widget.h"
#include "content_widget.h"
#include "common.h"
#include "drop_shadow_widget.h"

class Favorite : public DropShadowWidget
{
	Q_OBJECT

public:

	Favorite(QWidget *parent = 0);
	~Favorite();
	bool isRunning();

protected:

	virtual void paintEvent(QPaintEvent *event);

	public slots:

	void showWidget();

	private slots:

	void iconIsActived(QSystemTrayIcon::ActivationReason reason);

private:

	void initLocalConnection();

private:

	TitleWidget *title_widget; //标题栏
	ContentWidget *content_widget; //主界面内容
	SystemTray *system_tray; //托盘项

	bool is_running;

};

#endif // MAINWIDGET_H
