/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QLabel *labelTitle;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *loginButton;
    QRadioButton *doctorButton;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QLineEdit *emailEdit;
    QLabel *label;
    QRadioButton *patientButton;

    void setupUi(QDialog *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName(QString::fromUtf8("LoginScreen"));
        LoginScreen->resize(350, 200);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginScreen->sizePolicy().hasHeightForWidth());
        LoginScreen->setSizePolicy(sizePolicy);
        LoginScreen->setMinimumSize(QSize(350, 200));
        LoginScreen->setMaximumSize(QSize(350, 200));
        QFont font;
        font.setFamily(QString::fromUtf8("Menlo"));
        LoginScreen->setFont(font);
        labelTitle = new QLabel(LoginScreen);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(140, 20, 55, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Menlo"));
        font1.setPointSize(18);
        labelTitle->setFont(font1);
        widget = new QWidget(LoginScreen);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 70, 271, 97));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));
        loginButton->setEnabled(true);
        loginButton->setFont(font);

        gridLayout_2->addWidget(loginButton, 1, 2, 1, 1);

        doctorButton = new QRadioButton(widget);
        doctorButton->setObjectName(QString::fromUtf8("doctorButton"));
        doctorButton->setFont(font);

        gridLayout_2->addWidget(doctorButton, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        passwordEdit = new QLineEdit(widget);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setFont(font);
        passwordEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(passwordEdit, 1, 2, 1, 1);

        emailEdit = new QLineEdit(widget);
        emailEdit->setObjectName(QString::fromUtf8("emailEdit"));
        emailEdit->setFont(font);

        gridLayout->addWidget(emailEdit, 0, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        patientButton = new QRadioButton(widget);
        patientButton->setObjectName(QString::fromUtf8("patientButton"));
        patientButton->setFont(font);

        gridLayout_2->addWidget(patientButton, 1, 1, 1, 1);


        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QDialog *LoginScreen)
    {
        LoginScreen->setWindowTitle(QApplication::translate("LoginScreen", "Login", nullptr));
        labelTitle->setText(QApplication::translate("LoginScreen", "Login", nullptr));
        loginButton->setText(QApplication::translate("LoginScreen", "Login", nullptr));
        doctorButton->setText(QApplication::translate("LoginScreen", "Doctor", nullptr));
        label_2->setText(QApplication::translate("LoginScreen", "Password:", nullptr));
        passwordEdit->setInputMask(QString());
        label->setText(QApplication::translate("LoginScreen", "Email:", nullptr));
        patientButton->setText(QApplication::translate("LoginScreen", "Patient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
