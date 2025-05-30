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
    QGridLayout *gridLayout;
    QPushButton *addpatientButton;
    QPushButton *patientlistButton;
    QPushButton *signoffButton;
    QLabel *labelTitle;
    QPushButton *covidtestButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoctorMenu)
    {
        if (DoctorMenu->objectName().isEmpty())
            DoctorMenu->setObjectName(QString::fromUtf8("DoctorMenu"));
        DoctorMenu->resize(608, 397);
        DoctorMenu->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        DoctorMenu->setFont(font);
        centralwidget = new QWidget(DoctorMenu);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        addpatientButton = new QPushButton(centralwidget);
        addpatientButton->setObjectName(QString::fromUtf8("addpatientButton"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addpatientButton->sizePolicy().hasHeightForWidth());
        addpatientButton->setSizePolicy(sizePolicy);
        addpatientButton->setMaximumSize(QSize(200, 100));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Menlo"));
        addpatientButton->setFont(font1);

        gridLayout->addWidget(addpatientButton, 5, 0, 1, 1);

        patientlistButton = new QPushButton(centralwidget);
        patientlistButton->setObjectName(QString::fromUtf8("patientlistButton"));
        sizePolicy.setHeightForWidth(patientlistButton->sizePolicy().hasHeightForWidth());
        patientlistButton->setSizePolicy(sizePolicy);
        patientlistButton->setMaximumSize(QSize(200, 100));
        patientlistButton->setFont(font1);

        gridLayout->addWidget(patientlistButton, 3, 0, 1, 1);

        signoffButton = new QPushButton(centralwidget);
        signoffButton->setObjectName(QString::fromUtf8("signoffButton"));
        sizePolicy.setHeightForWidth(signoffButton->sizePolicy().hasHeightForWidth());
        signoffButton->setSizePolicy(sizePolicy);
        signoffButton->setMaximumSize(QSize(200, 100));
        signoffButton->setFont(font1);

        gridLayout->addWidget(signoffButton, 6, 0, 1, 1);

        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTitle->sizePolicy().hasHeightForWidth());
        labelTitle->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Menlo"));
        font2.setPointSize(30);
        labelTitle->setFont(font2);
        labelTitle->setLayoutDirection(Qt::LeftToRight);
        labelTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelTitle, 0, 0, 1, 1);

        covidtestButton = new QPushButton(centralwidget);
        covidtestButton->setObjectName(QString::fromUtf8("covidtestButton"));
        sizePolicy.setHeightForWidth(covidtestButton->sizePolicy().hasHeightForWidth());
        covidtestButton->setSizePolicy(sizePolicy);
        covidtestButton->setMaximumSize(QSize(200, 100));
        covidtestButton->setFont(font1);

        gridLayout->addWidget(covidtestButton, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        DoctorMenu->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoctorMenu);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 608, 24));
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
        addpatientButton->setText(QApplication::translate("DoctorMenu", "Add patient", nullptr));
        patientlistButton->setText(QApplication::translate("DoctorMenu", "Patient list", nullptr));
        signoffButton->setText(QApplication::translate("DoctorMenu", "Sign off", nullptr));
        labelTitle->setText(QApplication::translate("DoctorMenu", "Main menu", nullptr));
        covidtestButton->setText(QApplication::translate("DoctorMenu", "Covid test", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorMenu: public Ui_DoctorMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORMENU_H
