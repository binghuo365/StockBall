#include "SubGetDataThread.h"
#include "QNetworkAccessManager"
#include "QNetworkRequest"
#include "QTextCodec"
#include "QNetworkReply"
#include "QMessageBox"
#include "QFile"
#include "QDomDocument"

SubGetDataThread::SubGetDataThread(QObject *parent) :
QThread(parent), _response(true), network_manager(NULL)
{
}

SubGetDataThread::~SubGetDataThread()
{
}

void SubGetDataThread::run()
{
	WrTimer = new QTimer(this);
	connect(WrTimer, SIGNAL(timeout()), this, SLOT(TimerOut()), Qt::DirectConnection);
	WrTimer->start(1000);
	exec();
}
void SubGetDataThread::replyFinished(QNetworkReply *reply)  //当回复结束后  
{
	QTextCodec *codec = QTextCodec::codecForName("GB2312");
	QString all = codec->toUnicode(reply->readAll());
	QStringList strList = all.split('=');
	strList = strList[1].mid(1, strList[1].size() - 3).split(',');
	for (int i = 0; i < strList.size(); ++i)
	{
		//QMessageBox::about(NULL, "title", strList[i]);
	}

	reply->deleteLater();
	_response = true;
}

void SubGetDataThread::TimerOut()
{
	if (!_response)
	{
		return;
	}
	network_manager = new QNetworkAccessManager(this);
	connect(network_manager, SIGNAL(finished(QNetworkReply*)),
		this, SLOT(replyFinished(QNetworkReply*)));
	QUrl url;
	url.setUrl("http://hq.sinajs.cn/list=s_sh000001");
	QNetworkRequest network_request;
	network_request.setUrl(url);
	network_manager->get(network_request);
	_response = false;
}

