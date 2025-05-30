#include "addpatient.h"
#include <fstream>	
#include <iostream>
#include "regex_validation.h"
#include <QDebug>
#include <QtWidgets>
#include <QMessageBox>
#include "patient.h"
#include "person.h"
#include "ui_addpatient.h"
#include <QDir>

AddPatient::AddPatient(QWidget *_parent) : QDialog(_parent) {
	ui.setupUi(this);
}

void AddPatient::on_addButton_clicked() {
	QString name = ui.nameEdit->text();
	QString surname = ui.surnameEdit->text();
	QString email = ui.emailEdit->text();
	QString phone = ui.phoneEdit->text();
	
	if (name.isEmpty() || surname.isEmpty() || email.isEmpty() || phone.isEmpty()) {
		QMessageBox::warning(this, "Error", "Please fill in all the boxes");
		return;
	}
	else if (!(RegexValidation::IsValidated(ValType::EMail, email.toStdString()))) {
		QMessageBox::warning(this, "Error", "Not a valable e-mail adres");
		return;
		
	}

	else if (!(RegexValidation::IsValidated(ValType::GSM, phone.toStdString())) && !(RegexValidation::IsValidated(ValType::Phone, phone.toStdString()))) {
		QMessageBox::warning(this, "Error", "Not a valable phone number");
		return;

	}
	
	std::ofstream file_stream;
	
	file_stream.open("Data/patient.csv", std::ios::app);
	if (!file_stream.is_open()) {
		//Errror
	}

	//Patient CSV structure: name,surname,password,phoneNumber,email,positive,last_test_date
	std::string name_std = name.toStdString();
	std::string surname_std = surname.toStdString();
	std::string phone_std = phone.toStdString();
	std::string email_std = email.toStdString();
	std::string positive = "false";
	std::string last_test_date = "N/A";
	std::string password = "1234"; //Zorgen dat paswoord random gegenereerd wordt
	file_stream << name_std << ";" << surname_std << ";" << password << ";" << phone_std << ";" << email_std << ";" << positive << ";" << last_test_date << std::endl;
	file_stream.close();
	bool positive_bool = (positive == "true");
	Patient* new_patient = new Patient(name_std, surname_std, password, phone_std, email_std, positive_bool, last_test_date);
	emit patientAdded(new_patient);
	QMessageBox::information(this, "Succes", "A new patient has been added");
	this->accept();


}


AddPatient::~AddPatient() {
}
