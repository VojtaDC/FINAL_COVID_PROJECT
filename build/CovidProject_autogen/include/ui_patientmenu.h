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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientMenu
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QLabel *title;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout;
    QPushButton *accountButton;
    QSpacerItem *verticalSpacer;
    QPushButton *resultsButton;
    QSpacerItem *verticalSpacer_2;
    QPushButton *signoffButton;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatientMenu)
    {
        if (PatientMenu->objectName().isEmpty())
            PatientMenu->setObjectName(QString::fromUtf8("PatientMenu"));
        PatientMenu->resize(800, 600);
        centralwidget = new QWidget(PatientMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 10, 756, 533));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        title = new QLabel(layoutWidget);
        title->setObjectName(QString::fromUtf8("title"));
        QFont font;
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);

        verticalLayout_2->addWidget(title);

        verticalSpacer_4 = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        accountButton = new QPushButton(layoutWidget);
        accountButton->setObjectName(QString::fromUtf8("accountButton"));

        verticalLayout->addWidget(accountButton);

        verticalSpacer = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        resultsButton = new QPushButton(layoutWidget);
        resultsButton->setObjectName(QString::fromUtf8("resultsButton"));

        verticalLayout->addWidget(resultsButton);

        verticalSpacer_2 = new QSpacerItem(20, 28, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        signoffButton = new QPushButton(layoutWidget);
        signoffButton->setObjectName(QString::fromUtf8("signoffButton"));

        verticalLayout->addWidget(signoffButton);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 208, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        PatientMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PatientMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
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
        title->setText(QApplication::translate("PatientMenu", "Main menu", nullptr));
        accountButton->setText(QApplication::translate("PatientMenu", "My account", nullptr));
        resultsButton->setText(QApplication::translate("PatientMenu", "View results", nullptr));
        signoffButton->setText(QApplication::translate("PatientMenu", "Sign off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientMenu: public Ui_PatientMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTMENU_H
