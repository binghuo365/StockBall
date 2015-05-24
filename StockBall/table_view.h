#ifndef TABLEVIEW
#define TABLEVIEW
#include "QTableView"
#include "QTimer"

class TableView : public QTableView
{
	Q_OBJECT
public:
	explicit TableView(QWidget *parent = 0);
	~TableView();

public slots:
	void init();

protected:
	void paintEvent(QPaintEvent *e);

private:
	QTimer *WrTimer;
};
#endif
