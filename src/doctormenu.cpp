#include "doctormenu.h"
#include "addpatient.h"
#include "patientlist.h"
#include "sessionutils.h"
#include <QDebug>

DoctorMenu::DoctorMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
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

}

void DoctorMenu::on_addpatientButton_clicked() {
	AddPatient addpatient;
	addpatient.exec();
}
void DoctorMenu::on_signoffButton_clicked() {
	sessionutils::performSignOff(this);


}

