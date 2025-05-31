#include "doctor_menu.h"
#include "add_patient.h"
#include "patient_list.h"
#include "session_utils.h"
//#include "covid_test.h"
#include <QDebug>
#include "error_handling.h"

DoctorMenu::DoctorMenu(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setAttribute(Qt::WA_DeleteOnClose);
	QString user_first_name = SessionUtils::GetCurrentUserFirstName();
	if (user_first_name.isEmpty()) {
		ErrorType error = ErrorType::Session_Data_Missing;
		ErrorHandling::ReportError(error, "[DoctorMenu - Constructor]");
	}
	setWindowTitle("Doctor Dashboard");
	ui.labelTitle->setText("Welcome " + user_first_name + "!"); // Set the title label with the current user's name
}

void DoctorMenu::on_patientlistButton_clicked() {
	PatientList* patient_list = new PatientList();
	patient_list->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
	patient_list->setWindowModality(Qt::ApplicationModal); // Make it modal
	patient_list->show();

}
void DoctorMenu::on_covidtestButton_clicked() {
	//CovidTest* covidTest = new CovidTest();
	//covidTest->setAttribute(Qt::WA_DeleteOnClose); // Ensure proper cleanup
	//covidTest->setWindowModality(Qt::ApplicationModal); // Make it modal
	//covidTest->show();
}

void DoctorMenu::on_signoffButton_clicked() {
	SessionUtils::PerformSignOff(this);
}

DoctorMenu::~DoctorMenu() {
}
