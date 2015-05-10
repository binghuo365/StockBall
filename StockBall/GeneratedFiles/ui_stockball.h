/********************************************************************************
** Form generated from reading UI file 'stockball.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKBALL_H
#define UI_STOCKBALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockBallClass
{
public:

    void setupUi(QWidget *StockBallClass)
    {
        if (StockBallClass->objectName().isEmpty())
            StockBallClass->setObjectName(QStringLiteral("StockBallClass"));
        StockBallClass->resize(600, 400);

        retranslateUi(StockBallClass);

        QMetaObject::connectSlotsByName(StockBallClass);
    } // setupUi

    void retranslateUi(QWidget *StockBallClass)
    {
        StockBallClass->setWindowTitle(QApplication::translate("StockBallClass", "StockBall", 0));
    } // retranslateUi

};

namespace Ui {
    class StockBallClass: public Ui_StockBallClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKBALL_H
