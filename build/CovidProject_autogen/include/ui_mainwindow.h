/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWIndowClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWIndowClass)
    {
        if (MainWIndowClass->objectName().isEmpty())
            MainWIndowClass->setObjectName(QString::fromUtf8("MainWIndowClass"));
        MainWIndowClass->resize(600, 400);
        centralWidget = new QWidget(MainWIndowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWIndowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWIndowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 37));
        MainWIndowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWIndowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWIndowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWIndowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWIndowClass->setStatusBar(statusBar);

        retranslateUi(MainWIndowClass);

        QMetaObject::connectSlotsByName(MainWIndowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWIndowClass)
    {
        MainWIndowClass->setWindowTitle(QApplication::translate("MainWIndowClass", "MainWIndow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWIndowClass: public Ui_MainWIndowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
