#include "patientlist.h"
#include "patient.h"
#include "csvloader.h"
#include <QDebug>

PatientList::PatientList(QWidget *parent) : QMainWindow(parent), m_table_model(nullptr) {
	ui.setupUi(this);
	patients = CsvLoader::loadPersons("Data/patient.csv", "patient");
	m_table_model = new QStandardItemModel(this);
	m_filter_model = new PatientFilterModel(this);

	ui.patientView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.patientView->setSortingEnabled(true);

	m_filter_model->setSourceModel(m_table_model);
	ui.patientView->setModel(m_filter_model);

	fillTable();

	connect(ui.testresultBox, &QComboBox::currentTextChanged,  m_filter_model, &PatientFilterModel::setOption);
	connect(ui.searchEdit, &QLineEdit::textEdited,  m_filter_model, &PatientFilterModel::setSearch);
	connect(ui.patientView, &QTableView::clicked, this, &PatientList::onPatientClicked);

}

void PatientList::fillTable() {
	m_table_model->setColumnCount(3);
	m_table_model->setHorizontalHeaderLabels({ "Patient", "Positive", "Last test" });
	for (const auto& p : patients) {
		if (Patient* patient = dynamic_cast<Patient*>(p.get())) { //p.get returns a raw pointer but this pointer is still owned by the std::unique_ptr so destructor should not be called

			QList<QStandardItem*> row;
			auto fullname = new QStandardItem(QString::fromStdString(patient->getSurname() + " " + patient->getName()));
			auto positive = new QStandardItem(patient->isPositive() ? "Yes" : "No");
			auto last_test_date = new QStandardItem(QString::fromStdString(patient->getLastTestDate()));
			row << fullname <<  positive << last_test_date;
			m_table_model->appendRow(row);
		}
		else {
			//error geen patient object
		}
	}
	
}

void PatientList::onPatientClicked(const QModelIndex& _index) {
	if (!_index.isValid()) {
		//error
		return;
	}

	QModelIndex source_index = m_filter_model->mapToSource(_index); //Trought the connector you get an index from the filter model but because of sorting/filtering this does not necessarily correspond to the correct index from the source model(m_table_model)
	int row_number = source_index.row();
	
	if (row_number >= 0 && row_number < patients.size()) {
		Patient* patient = dynamic_cast<Patient*>(patients[row_number].get()); //Get patient out of patient vector
		if (patient) {
			m_patient_details = new PatientDetails(patient, this);
			m_patient_details->exec();
		}
	}
}

PatientList::~PatientList() {
}
