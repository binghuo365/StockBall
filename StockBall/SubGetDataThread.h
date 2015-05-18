#ifndef SUBGETDATATHREAD
#define SUBGETDATATHREAD

#include <QThread>
#include "QNetworkReply"
#include "QTimer"

class SubGetDataThread : public QThread
{
	Q_OBJECT
public:
	explicit SubGetDataThread(QObject *parent = 0);
	virtual ~SubGetDataThread();

	virtual void run();

public slots:
 	void replyFinished(QNetworkReply *reply);
	void TimerOut();

signals:
	void Signal(int);

private:
	QNetworkAccessManager* network_manager;
	QTimer *WrTimer;
	bool _response;
};

#endif 