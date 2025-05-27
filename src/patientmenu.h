#pragma once

#include "ui_patientmenu.h"

class PatientMenu : public QMainWindow
{
	Q_OBJECT

public:
	PatientMenu(QWidget *parent = Q_NULLPTR);
	//~PatientMenu();
	
private slots:
	void on_signoffButton_clicked();


private:
	Ui::PatientMenu ui;
};


