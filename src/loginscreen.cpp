#include "loginscreen.h"
#include "doctormenu.h"
#include "patientmenu.h"
#include <QDir>
#include <QDebug>
// …

LoginScreen::LoginScreen(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

    // Bepaal exe-dir en navigeer naar ../data
    QDir exeDir(QCoreApplication::applicationDirPath()); 
    exeDir.cdUp();             // nu in .../build/..
    exeDir.cd("data");         // nu in .../data
    QString patientFile = exeDir.filePath("patient.csv");
    QString doctorFile  = exeDir.filePath("doctor.csv");

    qDebug() << "Data-dir:" << exeDir.path();
    qDebug() << "Patient-file:" << patientFile;
    qDebug() << "Doctor-file:"  << doctorFile;

    patients = CsvLoader::loadPersons(patientFile.toStdString(), "patient");
    doctors  = CsvLoader::loadPersons(doctorFile.toStdString(),  "doctor");
}

void LoginScreen::on_loginButton_clicked() {
	QString username = ui.emailEdit->text();
	QString password = ui.passwordEdit->text();
	
	if (!ui.doctorButton->isChecked() && !ui.patientButton->isChecked()) {
		QMessageBox::warning(this, "Login failed", "You must check one of the boxes");
		return;
	}

	else if (ui.doctorButton->isChecked()) {
		for (const auto& person : doctors) {
			if (person->getEmail() == username.toStdString() && person->getPassword() == password.toStdString()) {
				DoctorMenu* doctorMenu = new DoctorMenu();
				doctorMenu->setAttribute(Qt::WA_DeleteOnClose);
				doctorMenu->show();
				this->close();
				return;
			}
		}
	}

	else if (ui.patientButton->isChecked()) {
		for (const auto& person : patients) {
			if (person->getEmail() == username.toStdString() && person->getPassword() == password.toStdString()) {
				PatientMenu* patientmenu = new PatientMenu();
				patientmenu->show();
				this->close();
				return;
			}
		}
	}
	
	
	QMessageBox::warning(this, "Login failed", "Wrong username or password");
	
}

