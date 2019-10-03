/********************************************************************************
** Form generated from reading UI file 'note.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTE_H
#define UI_NOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "imagecalendar.h"
#include "lednumber.h"

QT_BEGIN_NAMESPACE

class Ui_NoteClass
{
public:
    QWidget *centralWidget;
    ImageCalendar *imageCalendar;
    LedNumber *ledNumberL;
    LedNumber *ledNumberR;
    QTextEdit *textEditNote;
    QLabel *label_NextSee;
    QLabel *label_Note;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_Together;
    QPushButton *pushButtonHide;

    void setupUi(QMainWindow *NoteClass)
    {
        if (NoteClass->objectName().isEmpty())
            NoteClass->setObjectName(QStringLiteral("NoteClass"));
        NoteClass->resize(600, 400);
        centralWidget = new QWidget(NoteClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imageCalendar = new ImageCalendar(centralWidget);
        imageCalendar->setObjectName(QStringLiteral("imageCalendar"));
        imageCalendar->setGeometry(QRect(10, 10, 140, 158));
        ledNumberL = new LedNumber(centralWidget);
        ledNumberL->setObjectName(QStringLiteral("ledNumberL"));
        ledNumberL->setGeometry(QRect(360, 20, 111, 131));
        ledNumberR = new LedNumber(centralWidget);
        ledNumberR->setObjectName(QStringLiteral("ledNumberR"));
        ledNumberR->setGeometry(QRect(470, 20, 111, 131));
        textEditNote = new QTextEdit(centralWidget);
        textEditNote->setObjectName(QStringLiteral("textEditNote"));
        textEditNote->setGeometry(QRect(20, 200, 421, 191));
        label_NextSee = new QLabel(centralWidget);
        label_NextSee->setObjectName(QStringLiteral("label_NextSee"));
        label_NextSee->setGeometry(QRect(270, 30, 91, 20));
        label_Note = new QLabel(centralWidget);
        label_Note->setObjectName(QStringLiteral("label_Note"));
        label_Note->setGeometry(QRect(10, 170, 54, 12));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(150, 20, 120, 131));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 91, 16));
        label_Together = new QLabel(groupBox);
        label_Together->setObjectName(QStringLiteral("label_Together"));
        label_Together->setGeometry(QRect(20, 61, 81, 51));
        pushButtonHide = new QPushButton(centralWidget);
        pushButtonHide->setObjectName(QStringLiteral("pushButtonHide"));
        pushButtonHide->setGeometry(QRect(480, 190, 75, 23));
        NoteClass->setCentralWidget(centralWidget);

        retranslateUi(NoteClass);

        QMetaObject::connectSlotsByName(NoteClass);
    } // setupUi

    void retranslateUi(QMainWindow *NoteClass)
    {
        NoteClass->setWindowTitle(QApplication::translate("NoteClass", "Note", 0));
        label_NextSee->setText(QApplication::translate("NoteClass", "\350\267\235\347\246\273\350\247\201\351\235\242\350\277\230\346\234\211\357\274\232", 0));
        label_Note->setText(QApplication::translate("NoteClass", "\345\244\207\345\277\230\357\274\232", 0));
        groupBox->setTitle(QApplication::translate("NoteClass", "Together", 0));
        label->setText(QApplication::translate("NoteClass", "\346\210\221\344\273\254\345\234\250\344\270\200\350\265\267\357\274\232", 0));
        label_Together->setText(QApplication::translate("NoteClass", "TextLabel", 0));
        pushButtonHide->setText(QApplication::translate("NoteClass", "\351\232\220\350\227\217\347\250\213\345\272\217", 0));
    } // retranslateUi

};

namespace Ui {
    class NoteClass: public Ui_NoteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTE_H
