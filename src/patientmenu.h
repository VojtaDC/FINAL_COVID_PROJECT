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
	~PatientMenu();
	
private slots:
	void on_signoffButton_clicked();
	void on_accountButton_clicked(); 
	void on_resultsButton_clicked(); 

private:
	Ui::PatientMenu ui;
};


