#include "doctormenu.h"
#include "addpatient.h"

DoctorMenu::DoctorMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
}

void DoctorMenu::on_patientlistButton_clicked() {

}
void DoctorMenu::on_covidtestButton_clicked() {

}

void DoctorMenu::on_addpatientButton_clicked() {
	AddPatient addpatient;
	addpatient.exec();
}
void DoctorMenu::on_signoffButton_clicked() {

}

