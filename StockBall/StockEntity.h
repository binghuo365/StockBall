#include "QString"
#include <map>

const QString dataXml = "data.xml";			//自定义xml


class CEntity
{

public:
	CEntity() : name(), code(), index(0), value(0), percent(0), change(0)
	{}

public:
	QString name;
	QString code;
	int		index;

	double		value;		//值
	double		percent;	//浮动百分比
	double		change;	//变化
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
	const std::map<QString, CEntity*>& getFavirateEntity(){ return _mapFavirateEntity; }
	const std::map<QString, CEntity*>& getMainEntity(){ return _mapMainEntity; }
	const std::map<QString, CEntity*>& getAllEntity(){ return _mapEntity; }
	CEntity* get(QString code);

	//加载数据
	void loadData();

public:
	CStockManager() : _mapEntity(), _mapMainEntity(), _mapFavirateEntity()
	{}
	~CStockManager(){}

private:
	std::map<QString, CEntity*> _mapEntity;	//code:Entity 总的map
	std::map<QString, CEntity*>_mapMainEntity;	//悬浮球的
	std::map<QString, CEntity*>_mapFavirateEntity;	//面板上的
};


