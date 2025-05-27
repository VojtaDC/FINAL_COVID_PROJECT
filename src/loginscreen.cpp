#include "loginscreen.h"
#include "doctormenu.h"
#include "patientmenu.h"
#include <QDir>
#include <QDebug>

LoginScreen::LoginScreen(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

    QDir exeDir(QCoreApplication::applicationDirPath()); 
    exeDir.cdUp();             
    exeDir.cd("data");
    QString patientFile = exeDir.filePath("patient.csv");
    QString doctorFile  = exeDir.filePath("doctor.csv");

    // Laad de patiënten met de nieuwe template-gebaseerde methode
    patients = CsvLoader::load<Patient>(
        patientFile.toStdString(),
        [](auto &cols) -> std::unique_ptr<Patient> {
            if (cols.size() < 7) return nullptr;
            bool isPos = (cols[5] == "true");
            return std::make_unique<Patient>(
                cols[0], cols[1], cols[2], cols[3], cols[4], isPos, cols[6]);
        }
    );

    // Laad de dokters met de nieuwe template-gebaseerde methode
    doctors = CsvLoader::load<Doctor>(
        doctorFile.toStdString(),
        [](auto &cols) -> std::unique_ptr<Doctor> {
            if (cols.size() < 6) return nullptr;
            return std::make_unique<Doctor>(
                cols[0], cols[1], cols[2], cols[3], cols[4], cols[5]);
        }
    );
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

