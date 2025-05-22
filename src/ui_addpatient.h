/********************************************************************************
** Form generated from reading UI file 'addpatient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENT_H
#define UI_ADDPATIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPatient
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *title;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *nameEdit;
    QLineEdit *emailEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *phoneEdit;
    QLineEdit *surnameEdit;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AddPatient)
    {
        if (AddPatient->objectName().isEmpty())
            AddPatient->setObjectName(QString::fromUtf8("AddPatient"));
        AddPatient->resize(522, 366);
        layoutWidget = new QWidget(AddPatient);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(-1, 10, 511, 351));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        title = new QLabel(layoutWidget);
        title->setObjectName(QString::fromUtf8("title"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);

        horizontalLayout_3->addWidget(title);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        emailEdit = new QLineEdit(layoutWidget);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));

        gridLayout->addWidget(emailEdit, 1, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        phoneEdit = new QLineEdit(layoutWidget);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));

        gridLayout->addWidget(phoneEdit, 1, 3, 1, 1);

        surnameEdit = new QLineEdit(layoutWidget);
        surnameEdit->setObjectName(QString::fromUtf8("surnameEdit"));

        gridLayout->addWidget(surnameEdit, 0, 3, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        horizontalLayout->addWidget(addButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 4, 0, 1, 1);


        retranslateUi(AddPatient);

        QMetaObject::connectSlotsByName(AddPatient);
    } // setupUi

    void retranslateUi(QDialog *AddPatient)
    {
        AddPatient->setWindowTitle(QApplication::translate("AddPatient", "Dialog", nullptr));
        title->setText(QApplication::translate("AddPatient", "New Patient", nullptr));
        label_3->setText(QApplication::translate("AddPatient", "Surname:", nullptr));
        label_4->setText(QApplication::translate("AddPatient", "Phone:", nullptr));
        label->setText(QApplication::translate("AddPatient", "Name:", nullptr));
        label_2->setText(QApplication::translate("AddPatient", "Email:", nullptr));
        addButton->setText(QApplication::translate("AddPatient", "Add", nullptr));
        cancelButton->setText(QApplication::translate("AddPatient", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPatient: public Ui_AddPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENT_H
