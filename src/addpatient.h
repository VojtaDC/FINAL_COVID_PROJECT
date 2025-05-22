#pragma once

#include <QtWidgets>
#include <QMessageBox>
#include "ui_addpatient.h"
#include "person.h"
#include "regex_validation.h"

class AddPatient : public QDialog
{
	Q_OBJECT

public:
	AddPatient(QWidget *parent = Q_NULLPTR);
	//~AddPatient();
	
private slots:
	void on_addButton_clicked();
private:
	Ui::AddPatient ui;
};
