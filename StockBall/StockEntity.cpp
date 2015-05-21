#include "StockEntity.h"
#include "QFile"
#include "QDomDocument"
#include "QTextCodec"
#include "QDebug"

CStock::CStock()
{

}

CStock::~CStock()
{

}


CIndex::CIndex()
{

}

CIndex::~CIndex()
{

}

void CStockManager::loadData()
{
	QFile file(dataXml);
	if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
		qDebug() << "open for read error...";
	}
	QString errorStr;
	int errorLine;
	int errorColumn;

	QDomDocument doc;
	if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn)) {
		qDebug() << "setcontent error...";
		file.close();
	}
	file.close();
	QDomNodeList  lists = doc.elementsByTagName("branch");
	for (int i = 0; i < lists.size(); ++i)
	{
		QDomElement ele = lists.at(i).toElement();
		QDomNodeList list2s = ele.elementsByTagName("node");
		for (int j = 0; j < list2s.size(); ++j)
		{
			QDomElement ele2 = list2s.at(j).toElement();
			if (ele2.elementsByTagName("is_stock").at(0).toElement().text() == "0")
			{
				//是指数
				CIndex* index = new CIndex();
				index->code = ele2.attribute("id");
				index->index = j;
				index->name = ele2.elementsByTagName("name").at(0).toElement().text();
				_mapEntity[index->code] = index;
				if (ele.attribute("type") == "main")
				{
					_mapMainEntity[index->code] = index;
				}
				else
				{
					_mapFavirateEntity[index->code] = index;
				}
			}
			else
			{
				//股票
				CStock* stock = new CStock();
				stock->code = ele2.attribute("id");
				stock->index = j;
				stock->name = ele2.elementsByTagName("name").at(0).toElement().text();
				_mapEntity[stock->code] = stock;
				if (ele.attribute("type") == "favorite")
				{
					_mapFavirateEntity[stock->code] = stock;
				}
				else
				{
					_mapMainEntity[stock->code] = stock;
				}
			}
		}
	}
}

CStockManager* CStockManager::instance()
{
	static CStockManager inst;
	return &inst;
}


