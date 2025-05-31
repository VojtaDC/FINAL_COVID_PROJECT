#include "patient_menu.h"
#include "patient_details.h"
#include <QMessageBox>

PatientMenu::PatientMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose); // Ensure the menu is deleted when closed
	QString user_first_name = SessionUtils::GetCurrentUserFirstName();

	setWindowTitle("Patient Dashboard");
	ui.labelTitle->setText("Welcome " + user_first_name + "!"); // Set the title label with the current user's name

}

PatientMenu::~PatientMenu() {
}

void PatientMenu::on_signoffButton_clicked() {
	SessionUtils::PerformSignOff(this); // Use the template function
}
void PatientMenu::on_accountButton_clicked() {

	Patient* current_patient = SessionUtils::GetCurrentPatient();

	if (current_patient) {
		// Hergebruik PatientDetails om gegevens te tonen
		PatientDetails* accountDetails = new PatientDetails(current_patient, this);
		accountDetails->setWindowTitle("My Account");
		accountDetails->setAttribute(Qt::WA_DeleteOnClose);
		accountDetails->exec();
	}
	else {
		// Toon een foutmelding als er geen ingelogde patient is
		QMessageBox::warning(this, "Error", "No patient information available");
	}
}
void PatientMenu::on_resultsButton_clicked() {
	Patient* current_patient = SessionUtils::GetCurrentPatient();

	if (current_patient) {
		QString result = current_patient->isPositive() ? "Positive" : "Negative";
		QString date = QString::fromStdString(current_patient->getLastTestDate());

		QMessageBox msgBox;
		msgBox.setWindowTitle("COVID-19 Test Results");
		msgBox.setText("Your latest test result");
		msgBox.setInformativeText("Result: " + result + "\nDate: " + date);
		msgBox.setStandardButtons(QMessageBox::Ok);
		msgBox.exec();
	}
	else {
		QMessageBox::warning(this, "Error", "No patient information available");
	}
}
