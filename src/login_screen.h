#pragma once

#include <QtWidgets>
#include <QMessageBox>
#include "ui_loginscreen.h"
#include "person.h"
#include "csv_loader.h"
#include "patient.h"
#include "doctor.h"
#include "session_utils.h"
#include "paths.h"

class LoginScreen : public QDialog
{
	Q_OBJECT

public:
	LoginScreen(QWidget *parent = Q_NULLPTR);
	~LoginScreen();
	
private slots:
	void on_loginButton_clicked();
private:
	Ui::LoginScreen ui;
	std::vector<std::unique_ptr<Patient>> m_patients;
	std::vector<std::unique_ptr<Doctor>> m_doctors;
};
