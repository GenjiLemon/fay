/********************************************************************************
** Form generated from reading UI file 'frmimagecalendar.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMIMAGECALENDAR_H
#define UI_FRMIMAGECALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "imagecalendar.h"

QT_BEGIN_NAMESPACE

class Ui_frmImageCalendar
{
public:
    QGridLayout *gridLayout;
    ImageCalendar *imageCalendar1;
    ImageCalendar *imageCalendar2;
    ImageCalendar *imageCalendar3;
    ImageCalendar *imageCalendar4;
    ImageCalendar *imageCalendar5;
    ImageCalendar *imageCalendar6;

    void setupUi(QWidget *frmImageCalendar)
    {
        if (frmImageCalendar->objectName().isEmpty())
            frmImageCalendar->setObjectName(QStringLiteral("frmImageCalendar"));
        frmImageCalendar->resize(500, 316);
        gridLayout = new QGridLayout(frmImageCalendar);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(9, 0, 9, 0);
        imageCalendar1 = new ImageCalendar(frmImageCalendar);
        imageCalendar1->setObjectName(QStringLiteral("imageCalendar1"));

        gridLayout->addWidget(imageCalendar1, 0, 0, 1, 1);

        imageCalendar2 = new ImageCalendar(frmImageCalendar);
        imageCalendar2->setObjectName(QStringLiteral("imageCalendar2"));

        gridLayout->addWidget(imageCalendar2, 0, 1, 1, 1);

        imageCalendar3 = new ImageCalendar(frmImageCalendar);
        imageCalendar3->setObjectName(QStringLiteral("imageCalendar3"));

        gridLayout->addWidget(imageCalendar3, 0, 2, 1, 1);

        imageCalendar4 = new ImageCalendar(frmImageCalendar);
        imageCalendar4->setObjectName(QStringLiteral("imageCalendar4"));

        gridLayout->addWidget(imageCalendar4, 1, 0, 1, 1);

        imageCalendar5 = new ImageCalendar(frmImageCalendar);
        imageCalendar5->setObjectName(QStringLiteral("imageCalendar5"));

        gridLayout->addWidget(imageCalendar5, 1, 1, 1, 1);

        imageCalendar6 = new ImageCalendar(frmImageCalendar);
        imageCalendar6->setObjectName(QStringLiteral("imageCalendar6"));

        gridLayout->addWidget(imageCalendar6, 1, 2, 1, 1);


        retranslateUi(frmImageCalendar);

        QMetaObject::connectSlotsByName(frmImageCalendar);
    } // setupUi

    void retranslateUi(QWidget *frmImageCalendar)
    {
        frmImageCalendar->setWindowTitle(QApplication::translate("frmImageCalendar", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class frmImageCalendar: public Ui_frmImageCalendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMIMAGECALENDAR_H
