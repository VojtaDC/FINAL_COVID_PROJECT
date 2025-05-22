#pragma once

#include "ui_patientlist.h"
#include "person.h"

class PatientList : public QMainWindow
{
	Q_OBJECT

public:
	PatientList(QWidget *parent = Q_NULLPTR);
	//~PatientMenu();
	
private slots:
private:
	Ui::PatientList ui;
	std::vector<std::unique_ptr<Person>> patients;
	std::vector<const Person*> shown_patients;
	void fillTable();
};



