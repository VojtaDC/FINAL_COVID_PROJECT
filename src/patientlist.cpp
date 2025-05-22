#include "patientlist.h"
#include "csvloader.h"

PatientList::PatientList(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	patients = CsvLoader::loadPersons("data/patients.csv", "patient");

	for (const auto& patient : patients) {
		shown_patients.push_back(patient.get());

	}

}

void PatientList::fillTable() {
	ui.patientView;
}
