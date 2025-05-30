#include "patientmenu.h"
#include "sessionutils.h" 
#include "patientdetails.h"
#include <QMessageBox>

PatientMenu::PatientMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose); // Ensure the menu is deleted when closed
	QString userFirstName = sessionutils::getCurrentUserFirstName();
    
	setWindowTitle("Patient Dashboard");
	ui.labelTitle->setText("Welcome " + userFirstName+ "!"); // Set the title label with the current user's name
	
}

void PatientMenu::on_signoffButton_clicked() {
	sessionutils::performSignOff(this); // Use the template function
}
void PatientMenu::on_accountButton_clicked() {

	Patient* currentPatient = sessionutils::getCurrentPatient();
    
    if (currentPatient) {
        // Hergebruik PatientDetails om gegevens te tonen
        PatientDetails* accountDetails = new PatientDetails(currentPatient, this);
        accountDetails->setWindowTitle("My Account");
        accountDetails->setAttribute(Qt::WA_DeleteOnClose);
        accountDetails->exec();
    } else {
        // Toon een foutmelding als er geen ingelogde patiënt is
        QMessageBox::warning(this, "Error", "No patient information available");
    }
}
void PatientMenu::on_resultsButton_clicked() {
    Patient* currentPatient = sessionutils::getCurrentPatient();
    
    if (currentPatient) {
        QString result = currentPatient->getPositive() ? "Positive" : "Negative";
        QString date = QString::fromStdString(currentPatient->getLastTestDate());
        
        QMessageBox msgBox;
        msgBox.setWindowTitle("COVID-19 Test Results");
        msgBox.setText("Your latest test result");
        msgBox.setInformativeText("Result: " + result + "\nDate: " + date);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.exec();
    } else {
        QMessageBox::warning(this, "Error", "No patient information available");
    }
}