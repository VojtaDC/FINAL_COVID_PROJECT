#pragma once

#include <QtWidgets>
#include <QMessageBox>
#include "ui_loginscreen.h"
#include "person.h"
#include "doctor.h"
#include "patient.h"
#include "csvloader.h"

class LoginScreen : public QDialog
{
	Q_OBJECT

public:
	LoginScreen(QWidget *parent = Q_NULLPTR);
	//~LoginScreen();
	
private slots:
	void on_loginButton_clicked();
private:
	Ui::LoginScreen ui;
	std::vector<std::unique_ptr<Patient>> patients;
	std::vector<std::unique_ptr<Doctor>> doctors;
};
