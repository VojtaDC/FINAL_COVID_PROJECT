/********************************************************************************
** Form generated from reading UI file 'patientlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTLIST_H
#define UI_PATIENTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientList
{
public:
    QWidget *centralwidget;
    QTableView *patientView;
    QCheckBox *positiveBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatientList)
    {
        if (PatientList->objectName().isEmpty())
            PatientList->setObjectName(QString::fromUtf8("PatientList"));
        PatientList->resize(800, 600);
        centralwidget = new QWidget(PatientList);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        patientView = new QTableView(centralwidget);
        patientView->setObjectName(QString::fromUtf8("patientView"));
        patientView->setGeometry(QRect(30, 110, 721, 431));
        positiveBox = new QCheckBox(centralwidget);
        positiveBox->setObjectName(QString::fromUtf8("positiveBox"));
        positiveBox->setGeometry(QRect(360, 60, 101, 17));
        PatientList->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PatientList);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        PatientList->setMenuBar(menubar);
        statusbar = new QStatusBar(PatientList);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PatientList->setStatusBar(statusbar);

        retranslateUi(PatientList);

        QMetaObject::connectSlotsByName(PatientList);
    } // setupUi

    void retranslateUi(QMainWindow *PatientList)
    {
        PatientList->setWindowTitle(QApplication::translate("PatientList", "MainWindow", nullptr));
        positiveBox->setText(QApplication::translate("PatientList", "Show positive", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientList: public Ui_PatientList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTLIST_H
