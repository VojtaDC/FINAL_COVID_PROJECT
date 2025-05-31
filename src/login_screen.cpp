#include "login_screen.h"
#include "doctor_menu.h"
#include "patient_menu.h"
#include "error_handling.h"
#include <QDebug>


LoginScreen::LoginScreen(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	ErrorType error;
	qDebug() << getPersonsFilePath();
	CsvLoader::LoadAllPersons(getPersonsFilePath().toStdString(), m_patients, m_doctors, error);
	ErrorHandling::ReportError(error, "[LoginScreen - Constructor]");
}

void LoginScreen::on_loginButton_clicked() {
	QString username = ui.emailEdit->text();
	QString password = ui.passwordEdit->text();
	
	if (!ui.doctorButton->isChecked() && !ui.patientButton->isChecked()) {
		QMessageBox::warning(this, "Login failed", "You must check one of the boxes");
		return;
	}

	else if (ui.doctorButton->isChecked()) {
		for (const auto& doctor : m_doctors) {
			if (doctor->getEmail() == username.toStdString() && doctor->getPassword() == password.toStdString()) {
				SessionUtils::SetCurrentDoctor(doctor.get());
				DoctorMenu* doctor_menu = new DoctorMenu();
				doctor_menu->setAttribute(Qt::WA_DeleteOnClose);
				doctor_menu->show();
				this->close();
				return;
			}
		}
	}

	else if (ui.patientButton->isChecked()) {
		for (const auto& patient: m_patients) {
			if (patient->getEmail() == username.toStdString() && patient->getPassword() == password.toStdString()) {
				SessionUtils::SetCurrentPatient(patient.get());
				PatientMenu* patient_menu = new PatientMenu();
				patient_menu->show();
				this->close();
				return;
			}
		}
	}
	
	
	QMessageBox::warning(this, "Login failed", "Wrong username or password");
	
}

LoginScreen::~LoginScreen() {
}
