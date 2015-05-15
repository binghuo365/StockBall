#include "QString"
#include <map>

const QString dataXml = "data.xml";			//自定义xml


class CEntity
{

public:
	std::string name;
	std::string code;
	int		index;
};

class CStock
	: public CEntity
{
public:
	CStock();
	~CStock();
};

class CIndex
	: public CEntity
{
public:
	CIndex();
	~CIndex();
};

class CStockManager
{
public:

	static CStockManager* instance();

	//加载数据
	void loadData();

public:
	CStockManager() : _mapEntity(), _mapMainEntity(), _mapFavirateEntity()
	{}
	~CStockManager(){}

private:
	std::map<std::string, CEntity*> _mapEntity;	//code:Entity 总的map
	std::map<std::string, CEntity*>_mapMainEntity;	//悬浮球的
	std::map<std::string, CEntity*>_mapFavirateEntity;	//面板上的
};


