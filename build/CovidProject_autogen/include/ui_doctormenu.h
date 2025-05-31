/********************************************************************************
** Form generated from reading UI file 'doctormenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORMENU_H
#define UI_DOCTORMENU_H

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

class Ui_DoctorMenu
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout;
    QPushButton *covidtestButton;
    QPushButton *signoffButton;
    QLabel *labelTitle;
    QPushButton *patientlistButton;
    QPushButton *accountButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoctorMenu)
    {
        if (DoctorMenu->objectName().isEmpty())
            DoctorMenu->setObjectName(QString::fromUtf8("DoctorMenu"));
        DoctorMenu->resize(632, 581);
        DoctorMenu->setMinimumSize(QSize(0, 0));
        DoctorMenu->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Menlo"));
        font.setBold(true);
        font.setWeight(75);
        DoctorMenu->setFont(font);
        centralwidget = new QWidget(DoctorMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 2, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        covidtestButton = new QPushButton(centralwidget);
        covidtestButton->setObjectName(QString::fromUtf8("covidtestButton"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(covidtestButton->sizePolicy().hasHeightForWidth());
        covidtestButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(covidtestButton, 4, 0, 1, 1);

        signoffButton = new QPushButton(centralwidget);
        signoffButton->setObjectName(QString::fromUtf8("signoffButton"));
        sizePolicy.setHeightForWidth(signoffButton->sizePolicy().hasHeightForWidth());
        signoffButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(signoffButton, 6, 0, 1, 1);

        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(30);
        labelTitle->setFont(font1);

        gridLayout->addWidget(labelTitle, 1, 0, 1, 1);

        patientlistButton = new QPushButton(centralwidget);
        patientlistButton->setObjectName(QString::fromUtf8("patientlistButton"));
        sizePolicy.setHeightForWidth(patientlistButton->sizePolicy().hasHeightForWidth());
        patientlistButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(patientlistButton, 3, 0, 1, 1);

        accountButton = new QPushButton(centralwidget);
        accountButton->setObjectName(QString::fromUtf8("accountButton"));
        sizePolicy.setHeightForWidth(accountButton->sizePolicy().hasHeightForWidth());
        accountButton->setSizePolicy(sizePolicy);

        gridLayout->addWidget(accountButton, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        DoctorMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoctorMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 632, 24));
        DoctorMenu->setMenuBar(menubar);
        statusbar = new QStatusBar(DoctorMenu);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DoctorMenu->setStatusBar(statusbar);

        retranslateUi(DoctorMenu);

        QMetaObject::connectSlotsByName(DoctorMenu);
    } // setupUi

    void retranslateUi(QMainWindow *DoctorMenu)
    {
        DoctorMenu->setWindowTitle(QApplication::translate("DoctorMenu", "Main menu", nullptr));
        covidtestButton->setText(QApplication::translate("DoctorMenu", "Covid test", nullptr));
        signoffButton->setText(QApplication::translate("DoctorMenu", "Sign off", nullptr));
        labelTitle->setText(QApplication::translate("DoctorMenu", "Main menu", nullptr));
        patientlistButton->setText(QApplication::translate("DoctorMenu", "Patient list", nullptr));
        accountButton->setText(QApplication::translate("DoctorMenu", "My account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorMenu: public Ui_DoctorMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORMENU_H
