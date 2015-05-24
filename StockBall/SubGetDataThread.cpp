#include "SubGetDataThread.h"
#include "QNetworkAccessManager"
#include "QNetworkRequest"
#include "QTextCodec"
#include "QNetworkReply"
#include "QMessageBox"
#include "QFile"
#include "QDomDocument"
#include "StockEntity.h"

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
	QStringList stockList = all.split(';');
	for (int i = 0; i < stockList.size() - 1; ++i)
	{
		//单个股票处理
		QStringList stockTemp = stockList[i].split('=');
		QStringList stockAttrs = stockTemp[1].mid(1, stockTemp[1].size() - 2).split(',');
		//填充map
		CEntity* stock = CStockManager::instance()->get(stockTemp[0].split('_')[stockTemp[0].split('_').size() - 1]);
		if (NULL != stock)
		{
			stock->change = stockAttrs[3].toDouble();
			stock->percent = stockAttrs[2].toDouble();
			stock->value = stockAttrs[1].toDouble();
		}
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
	QString requestStocks;
	QString api = "http://hq.sinajs.cn/list=";
	const std::map<QString, CEntity*>& allMap = CStockManager::instance()->getAllEntity();
	int i = 0;
	for (std::map<QString, CEntity*>::const_iterator it = allMap.begin();
		it != allMap.end(); ++it, ++i)
	{
		if (i != allMap.size() - 1)
		{
			requestStocks += it->second->code + ",";
		}
		else
		{
			requestStocks += it->second->code;
		}
	}
	network_manager = new QNetworkAccessManager(this);
	connect(network_manager, SIGNAL(finished(QNetworkReply*)),
		this, SLOT(replyFinished(QNetworkReply*)));
	QUrl url;
	url.setUrl(api + requestStocks);
	QNetworkRequest network_request;
	network_request.setUrl(url);
	network_manager->get(network_request);
	_response = false;
}

