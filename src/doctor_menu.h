#pragma once

#include "ui_doctormenu.h"

class DoctorMenu : public QMainWindow
{
	Q_OBJECT

public:
	DoctorMenu(QWidget *parent = Q_NULLPTR);
	~DoctorMenu();
	
private slots:
	void on_patientlistButton_clicked();
	void on_covidtestButton_clicked();
	void on_signoffButton_clicked();
private:
	Ui::DoctorMenu ui;
};

