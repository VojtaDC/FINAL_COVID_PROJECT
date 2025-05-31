#include "add_patient.h"
#include <fstream>	
#include <iostream>
#include <QDebug>
#include "patient.h"
#include "paths.h"
#include "error_handling.h"

AddPatient::AddPatient(QWidget *parent) {
	ui.setupUi(this);
}


void AddPatient::on_addButton_clicked() {
	ErrorType error = ErrorType::No_Error;
	QString name = ui.nameEdit->text();
	QString surname = ui.surnameEdit->text();
	QString email = ui.emailEdit->text();
	QString phone = ui.phoneEdit->text();

	
	if (name.isEmpty() || surname.isEmpty() || email.isEmpty() || phone.isEmpty()) {
		QMessageBox::warning(this, "Error", "Please fill in all the boxes");
		return;
	}

	else if (!(RegexValidation::IsValidated(ValType::EMail, email))) {
		QMessageBox::warning(this, "Error", "Not a valable e-mail adres");
		return;
		
	}

	else if (!(RegexValidation::IsValidated(ValType::GSM, phone)) && !(RegexValidation::IsValidated(ValType::Phone, phone))) {
		QMessageBox::warning(this, "Error", "Not a valable phone number");
		return;

	}

	std::ofstream file_stream;
	file_stream.open(getPersonsFilePath().toStdString(), std::ios::app);
	if (!file_stream.is_open()) {
		error = ErrorType::File_Open_Failed;
		ErrorHandling::ReportError(error, "[AddPatient - on_addButton_clicked");
		return;
	}

	//SV structure: Role;Name;Surname;Password;Phonenumber;Email;Specialiaztion;Positive;Last_test_date
	std::string role = "Patient";
	std::string name_std = name.toStdString();
	std::string surname_std = surname.toStdString();
	std::string phone_std = phone.toStdString();
	std::string email_std = email.toStdString();
	std::string positive = "false";
	std::string last_test_date = "N/A";
	std::string password = "1234"; //Zorgen dat paswoord random gegenereerd wordt
	//file_stream << std::endl;
	file_stream << role << ";" << name_std << ";" << surname_std << ";" << password << ";" << phone_std << ";" << email_std << ";;" << positive << ";" << last_test_date << std::endl;
	if (!file_stream) {
		error = ErrorType::File_Write_Failed;
		ErrorHandling::ReportError(error, "[AddPatient - on_addButton_clicked");
	}
	file_stream.close();

	bool positive_bool = (positive == "true");
	Patient* new_patient = new Patient(name_std, surname_std, password, phone_std, email_std, positive_bool, last_test_date);
	emit patientAdded(new_patient);
	QMessageBox::information(this, "Succes", "A new patient has been added");
	this->accept();


}

AddPatient::~AddPatient() {
}

