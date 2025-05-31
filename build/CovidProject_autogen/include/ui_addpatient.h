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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_AddPatient
{
public:
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *nameEdit;
    QLineEdit *emailEdit;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *phoneEdit;
    QLineEdit *surnameEdit;
    QPushButton *addButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QLabel *title;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *AddPatient)
    {
        if (AddPatient->objectName().isEmpty())
            AddPatient->setObjectName(QString::fromUtf8("AddPatient"));
        AddPatient->resize(598, 429);
        AddPatient->setMaximumSize(QSize(800, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Menlo"));
        AddPatient->setFont(font);
        gridLayout_3 = new QGridLayout(AddPatient);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(AddPatient);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(AddPatient);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        nameEdit = new QLineEdit(AddPatient);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        emailEdit = new QLineEdit(AddPatient);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));
        emailEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(emailEdit, 1, 1, 1, 1);

        label = new QLabel(AddPatient);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(AddPatient);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        phoneEdit = new QLineEdit(AddPatient);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        phoneEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(phoneEdit, 1, 3, 1, 1);

        surnameEdit = new QLineEdit(AddPatient);
        surnameEdit->setObjectName(QString::fromUtf8("surnameEdit"));
        surnameEdit->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(surnameEdit, 0, 3, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 2);

        addButton = new QPushButton(AddPatient);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout_2->addWidget(addButton, 5, 0, 1, 1);

        cancelButton = new QPushButton(AddPatient);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout_2->addWidget(cancelButton, 5, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        title = new QLabel(AddPatient);
        title->setObjectName(QString::fromUtf8("title"));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        title->setFont(font1);
        title->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(title, 0, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_4, 2, 1, 1, 1);


        retranslateUi(AddPatient);

        QMetaObject::connectSlotsByName(AddPatient);
    } // setupUi

    void retranslateUi(QDialog *AddPatient)
    {
        AddPatient->setWindowTitle(QApplication::translate("AddPatient", "Add patient", nullptr));
        label_3->setText(QApplication::translate("AddPatient", "Surname:", nullptr));
        label_4->setText(QApplication::translate("AddPatient", "Phone:", nullptr));
        label->setText(QApplication::translate("AddPatient", "Name:", nullptr));
        label_2->setText(QApplication::translate("AddPatient", "Email:", nullptr));
        addButton->setText(QApplication::translate("AddPatient", "Add", nullptr));
        cancelButton->setText(QApplication::translate("AddPatient", "Cancel", nullptr));
        title->setText(QApplication::translate("AddPatient", "New Patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPatient: public Ui_AddPatient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENT_H
