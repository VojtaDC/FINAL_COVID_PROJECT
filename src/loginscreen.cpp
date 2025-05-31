#include "loginscreen.h"
#include "doctormenu.h"
#include "patientmenu.h"
// #include "error_handling.h"


LoginScreen::LoginScreen(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	// ErrorType error;
	CsvLoader::LoadAllPersons(getPersonsFilePath().toStdString(), m_patients, m_doctors);
	// ErrorHandling::ReportError(error, "LoginScreen - Constructor");
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
				sessionutils::setCurrentDoctor(doctor.get());
				DoctorMenu* doctormenu = new DoctorMenu();
				doctormenu->setAttribute(Qt::WA_DeleteOnClose);
				doctormenu->show();
				this->close();
				return;
			}
		}
	}

	else if (ui.patientButton->isChecked()) {
		for (const auto& patient: m_patients) {
			if (patient->getEmail() == username.toStdString() && patient->getPassword() == password.toStdString()) {
				sessionutils::setCurrentPatient(patient.get());
				
				PatientMenu* patientmenu = new PatientMenu();
				patientmenu->setAttribute(Qt::WA_DeleteOnClose);
				patientmenu->show();
				this->close();
				return;
			}
		}
	}
	
	
	QMessageBox::warning(this, "Login failed", "Wrong username or password");
	
}

LoginScreen::~LoginScreen() {
}
