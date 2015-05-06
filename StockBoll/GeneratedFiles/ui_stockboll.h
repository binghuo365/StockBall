/********************************************************************************
** Form generated from reading UI file 'stockboll.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKBOLL_H
#define UI_STOCKBOLL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockBollClass
{
public:

    void setupUi(QWidget *StockBollClass)
    {
        if (StockBollClass->objectName().isEmpty())
            StockBollClass->setObjectName(QStringLiteral("StockBollClass"));
        StockBollClass->resize(375, 280);

        retranslateUi(StockBollClass);

        QMetaObject::connectSlotsByName(StockBollClass);
    } // setupUi

    void retranslateUi(QWidget *StockBollClass)
    {
        StockBollClass->setWindowTitle(QApplication::translate("StockBollClass", "StockBoll", 0));
    } // retranslateUi

};

namespace Ui {
    class StockBollClass: public Ui_StockBollClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKBOLL_H
