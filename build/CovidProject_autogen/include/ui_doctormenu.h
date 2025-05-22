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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorMenu
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *title;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QPushButton *patientlistButton;
    QSpacerItem *verticalSpacer_4;
    QPushButton *covidtestButton;
    QSpacerItem *verticalSpacer_6;
    QPushButton *addpatientButton;
    QSpacerItem *verticalSpacer_5;
    QPushButton *signoffButton;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoctorMenu)
    {
        if (DoctorMenu->objectName().isEmpty())
            DoctorMenu->setObjectName(QString::fromUtf8("DoctorMenu"));
        DoctorMenu->resize(1045, 677);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        DoctorMenu->setFont(font);
        centralwidget = new QWidget(DoctorMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 1, 811, 581));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(238, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        title = new QLabel(layoutWidget);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(30);
        title->setFont(font1);

        verticalLayout_2->addWidget(title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        patientlistButton = new QPushButton(layoutWidget);
        patientlistButton->setObjectName(QString::fromUtf8("patientlistButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(patientlistButton->sizePolicy().hasHeightForWidth());
        patientlistButton->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(patientlistButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        covidtestButton = new QPushButton(layoutWidget);
        covidtestButton->setObjectName(QString::fromUtf8("covidtestButton"));

        verticalLayout->addWidget(covidtestButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        addpatientButton = new QPushButton(layoutWidget);
        addpatientButton->setObjectName(QString::fromUtf8("addpatientButton"));

        verticalLayout->addWidget(addpatientButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        signoffButton = new QPushButton(layoutWidget);
        signoffButton->setObjectName(QString::fromUtf8("signoffButton"));

        verticalLayout->addWidget(signoffButton);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 208, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        DoctorMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoctorMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1045, 21));
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
        title->setText(QApplication::translate("DoctorMenu", "Main menu", nullptr));
        patientlistButton->setText(QApplication::translate("DoctorMenu", "Patient list", nullptr));
        covidtestButton->setText(QApplication::translate("DoctorMenu", "Covid test", nullptr));
        addpatientButton->setText(QApplication::translate("DoctorMenu", "Add patient", nullptr));
        signoffButton->setText(QApplication::translate("DoctorMenu", "Sign off", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorMenu: public Ui_DoctorMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORMENU_H
