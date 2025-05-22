#include "addpatient.h"
#include <fstream>	
#include <iostream>
#include <QDebug>

AddPatient::AddPatient(QWidget *parent) {
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

	else if (!(RegexValidation::isValidated(ValType::EMail, email.toStdString()))) {
		QMessageBox::warning(this, "Error", "Not a valable e-mail adres");
		return;
		
	}

	else if (!(RegexValidation::isValidated(ValType::GSM, phone.toStdString())) && !(RegexValidation::isValidated(ValType::Phone, phone.toStdString()))) {
		QMessageBox::warning(this, "Error", "Not a valable phone number");
		return;

	}

	std::ofstream file_stream;
	file_stream.open("Data/patient.csv", std::ios::app);
	if (!file_stream.is_open()) {
		//Errror
	}

	//Patient CSV structure: name,surname,password,phoneNumber,email,positive,last_test_date
	std::string positive = "false";
	std::string last_test_date = "N/A";
	std::string password = "1234"; //Zorgen dat paswoord random gegenereerd wordt
	file_stream << name.toStdString() << ";" << surname.toStdString() << ";" << password << ";" << phone.toStdString() << ";" << email.toStdString() << ";" << positive << ";" << last_test_date << std::endl;
	file_stream.close();
	QMessageBox::information(this, "Succes", "A new patient has been added");
	this->accept();

}

