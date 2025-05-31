/********************************************************************************
** Form generated from reading UI file 'patientmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTMENU_H
#define UI_PATIENTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QPushButton *signoffButton;
    QPushButton *resultsButton;
    QLabel *labelTitle;
    QPushButton *accountButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatientMenu)
    {
        if (PatientMenu->objectName().isEmpty())
            PatientMenu->setObjectName(QString::fromUtf8("PatientMenu"));
        PatientMenu->resize(800, 600);
        PatientMenu->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Menlo"));
        PatientMenu->setFont(font);
        centralwidget = new QWidget(PatientMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 1);

        signoffButton = new QPushButton(centralwidget);
        signoffButton->setObjectName(QString::fromUtf8("signoffButton"));
        signoffButton->setFont(font);

        gridLayout->addWidget(signoffButton, 5, 0, 1, 1);

        resultsButton = new QPushButton(centralwidget);
        resultsButton->setObjectName(QString::fromUtf8("resultsButton"));
        resultsButton->setFont(font);

        gridLayout->addWidget(resultsButton, 3, 0, 1, 1);

        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Menlo"));
        font1.setPointSize(30);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        accountButton = new QPushButton(centralwidget);
        accountButton->setObjectName(QString::fromUtf8("accountButton"));
        accountButton->setFont(font);

        gridLayout->addWidget(accountButton, 4, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);

        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        PatientMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PatientMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        PatientMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(PatientMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PatientMenu->setStatusBar(statusbar);

        retranslateUi(PatientMenu);

        QMetaObject::connectSlotsByName(PatientMenu);
    } // setupUi

    void retranslateUi(QMainWindow *PatientMenu)
    {
        PatientMenu->setWindowTitle(QApplication::translate("PatientMenu", "MainWindow", nullptr));
        signoffButton->setText(QApplication::translate("PatientMenu", "Sign off", nullptr));
        resultsButton->setText(QApplication::translate("PatientMenu", "View results", nullptr));
        labelTitle->setText(QApplication::translate("PatientMenu", "Main menu", nullptr));
        accountButton->setText(QApplication::translate("PatientMenu", "My account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientMenu: public Ui_PatientMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMENU_H
