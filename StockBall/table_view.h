#ifndef TABLEVIEW
#define TABLEVIEW
#include "QTableView"

class TableView : public QTableView
{
	Q_OBJECT
public:
	explicit TableView(QWidget *parent = 0);
	~TableView();

	void init();

protected:
	void paintEvent(QPaintEvent *e);

private:

};
#endif
