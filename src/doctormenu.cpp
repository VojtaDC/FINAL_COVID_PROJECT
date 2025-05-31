#include "doctormenu.h"
#include "addpatient.h"
#include "patientlist.h"
#include "sessionutils.h"
#include "covidtest.h"
#include <QDebug>

DoctorMenu::DoctorMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);

	setAttribute(Qt::WA_DeleteOnClose);
	QString userFirstName = sessionutils::getCurrentUserFirstName();
    
	setWindowTitle("Doctor Dashboard");
	ui.labelTitle->setText("Welcome " + userFirstName+ "!"); // Set the title label with the current user's name
	
}

void DoctorMenu::on_patientlistButton_clicked() {
	qDebug() << "Patient list button clicked!";
	PatientList* patientlist = new PatientList();
	patientlist->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
	patientlist->setWindowModality(Qt::ApplicationModal); // Make it modal
	patientlist->show();
	qDebug() << "PatientList window created and shown";
}

void DoctorMenu::on_covidtestButton_clicked() {
	qDebug() << "Covid test button clicked!";
	CovidTest* covidTest = new CovidTest();
	covidTest->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
	covidTest->setWindowModality(Qt::ApplicationModal); // Make it modal
	covidTest->show();
	qDebug() << "CovidTest window created and shown";
}

void DoctorMenu::on_signoffButton_clicked() {
	sessionutils::performSignOff(this);
}

DoctorMenu::~DoctorMenu() {
}
