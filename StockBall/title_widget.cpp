#include "title_widget.h"

TitleWidget::TitleWidget(QWidget *parent)
	: QWidget(parent)
{
    version_title = new QLabel();
    min_button = new PushButton();
    close_button = new PushButton();

	version_title->setObjectName("whiteLabel");

	//ÉèÖÃÍ¼Æ¬
	min_button->setPicName(QString(":/sysButton/min"));
	close_button->setPicName(QString(":/sysButton/close"));

	connect(min_button, SIGNAL(clicked()), this, SIGNAL(showMin()));
    connect(close_button, SIGNAL(clicked()), this, SIGNAL(closeWidget()));

    QHBoxLayout *title_layout = new QHBoxLayout();
    title_layout->addWidget(version_title,0,Qt::AlignVCenter);
    title_layout->addStretch();
    title_layout->addWidget(min_button, 0, Qt::AlignTop);
    title_layout->addWidget(close_button, 0, Qt::AlignTop);
	title_layout->setSpacing(0);
	title_layout->setContentsMargins(0, 0, 5, 0);
	version_title->setContentsMargins(15, 0, 0, 0);

	setLayout(title_layout);
    setFixedHeight(30);
    is_move = false;
}