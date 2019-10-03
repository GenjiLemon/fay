/********************************************************************************
** Form generated from reading UI file 'frmlednumber.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLEDNUMBER_H
#define UI_FRMLEDNUMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "lednumber.h"

QT_BEGIN_NAMESPACE

class Ui_frmLedNumber
{
public:
    QHBoxLayout *horizontalLayout;
    LedNumber *ledNumber1;
    LedNumber *ledNumber2;

    void setupUi(QWidget *frmLedNumber)
    {
        if (frmLedNumber->objectName().isEmpty())
            frmLedNumber->setObjectName(QStringLiteral("frmLedNumber"));
        frmLedNumber->resize(500, 300);
        horizontalLayout = new QHBoxLayout(frmLedNumber);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ledNumber1 = new LedNumber(frmLedNumber);
        ledNumber1->setObjectName(QStringLiteral("ledNumber1"));

        horizontalLayout->addWidget(ledNumber1);

        ledNumber2 = new LedNumber(frmLedNumber);
        ledNumber2->setObjectName(QStringLiteral("ledNumber2"));

        horizontalLayout->addWidget(ledNumber2);


        retranslateUi(frmLedNumber);

        QMetaObject::connectSlotsByName(frmLedNumber);
    } // setupUi

    void retranslateUi(QWidget *frmLedNumber)
    {
        frmLedNumber->setWindowTitle(QApplication::translate("frmLedNumber", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class frmLedNumber: public Ui_frmLedNumber {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLEDNUMBER_H
