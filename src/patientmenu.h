#pragma once

#include "ui_patientmenu.h"
#include "patientdetails.h"
#include "patient.h"
#include "sessionutils.h"

class PatientMenu : public QMainWindow
{
	Q_OBJECT

public:
	PatientMenu(QWidget *parent = Q_NULLPTR);
	//~PatientMenu();
	
private slots:
	void on_signoffButton_clicked();
	void on_accountButton_clicked(); // Add this line
	void on_resultsButton_clicked(); // Add this line for results button functionality

private:
	Ui::PatientMenu ui;
};


