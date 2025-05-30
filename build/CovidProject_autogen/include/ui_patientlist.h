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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientList
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QComboBox *testresultBox;
    QTableView *patientView;
    QLineEdit *searchEdit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PatientList)
    {
        if (PatientList->objectName().isEmpty())
            PatientList->setObjectName(QString::fromUtf8("PatientList"));
        PatientList->resize(800, 600);
        PatientList->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(PatientList);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        testresultBox = new QComboBox(centralwidget);
        testresultBox->addItem(QString());
        testresultBox->addItem(QString());
        testresultBox->addItem(QString());
        testresultBox->setObjectName(QString::fromUtf8("testresultBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("Menlo"));
        testresultBox->setFont(font);

        gridLayout->addWidget(testresultBox, 0, 2, 1, 1);

        patientView = new QTableView(centralwidget);
        patientView->setObjectName(QString::fromUtf8("patientView"));
        patientView->setFont(font);

        gridLayout->addWidget(patientView, 1, 0, 1, 3);

        searchEdit = new QLineEdit(centralwidget);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));
        searchEdit->setFont(font);

        gridLayout->addWidget(searchEdit, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        PatientList->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PatientList);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        PatientList->setMenuBar(menubar);
        statusbar = new QStatusBar(PatientList);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        PatientList->setStatusBar(statusbar);

        retranslateUi(PatientList);

        QMetaObject::connectSlotsByName(PatientList);
    } // setupUi

    void retranslateUi(QMainWindow *PatientList)
    {
        PatientList->setWindowTitle(QApplication::translate("PatientList", "Patient list", nullptr));
        testresultBox->setItemText(0, QApplication::translate("PatientList", "All", nullptr));
        testresultBox->setItemText(1, QApplication::translate("PatientList", "Positive", nullptr));
        testresultBox->setItemText(2, QApplication::translate("PatientList", "Negative", nullptr));

        searchEdit->setPlaceholderText(QApplication::translate("PatientList", "Search patient...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientList: public Ui_PatientList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTLIST_H
