#include "loginscreen.h"
#include "doctormenu.h"
#include "patientmenu.h"
#include <QDir>
#include <QDebug>
#include "sessionutils.h"

LoginScreen::LoginScreen(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	setWindowTitle("Hospital System");

    QDir exeDir(QCoreApplication::applicationDirPath()); 
    exeDir.cdUp();             
    exeDir.cd("data");
    QString personsFile = exeDir.filePath("persons.csv");

    // Laad alle personen uit één bestand met de nieuwe type-gebaseerde methode
    auto allPersons = CsvLoader::loadAllPersons(personsFile.toStdString());
    
    // Filter patients en doctors uit de gecombineerde lijst
    patients = CsvLoader::filterPatients(allPersons);
    doctors = CsvLoader::filterDoctors(allPersons);
}

void LoginScreen::on_loginButton_clicked() {
	QString username = ui.emailEdit->text();
	QString password = ui.passwordEdit->text();
	
	if (!ui.doctorButton->isChecked() && !ui.patientButton->isChecked()) {
		QMessageBox::warning(this, "Login failed", "You must check one of the boxes");
		return;
	}

	else if (ui.doctorButton->isChecked()) {
		for (const auto& doctor : doctors) {
			if (doctor->getEmail() == username.toStdString() && doctor->getPassword() == password.toStdString()) {
				// Hier kun je nu dokter-specifieke functionaliteit gebruiken als nodig
				// Bijvoorbeeld: QString specialization = QString::fromStdString(doctor->getSpecialization());
				
				DoctorMenu* doctorMenu = new DoctorMenu();
				doctorMenu->setAttribute(Qt::WA_DeleteOnClose);
				doctorMenu->show();
				this->close();
				return;
			}
		}
	}

	else if (ui.patientButton->isChecked()) {
		for (const auto& patient : patients) {
			if (patient->getEmail() == username.toStdString() && patient->getPassword() == password.toStdString()) {
				// Hier kun je nu patiënt-specifieke functionaliteit gebruiken als nodig
				// Bijvoorbeeld: bool testResult = patient->getPositive();
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

