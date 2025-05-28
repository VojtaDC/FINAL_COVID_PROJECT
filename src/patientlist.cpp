#include "patientlist.h"
#include "csvloader.h"

PatientList::PatientList(QWidget *parent) : QMainWindow(parent) {
	ui.setupUi(this);
	
	// Use the new type-based approach
	auto allPersons = CsvLoader::loadAllPersons("data/persons.csv");
	
	// Convert specific patients to Person pointers
	for (const auto& person : allPersons) {
		if (dynamic_cast<Patient*>(person.get())) {
			// Move the Patient from allPersons to patients vector
			patients.push_back(std::move(const_cast<std::unique_ptr<Person>&>(person)));
		}
	}
}

void PatientList::fillTable() {
	// Implement table filling logic here
	// ui.patientView->setModel(...);
}
