#include "patient_list.h"
#include "add_patient.h"
#include "patient.h"
#include "csv_loader.h"
#include <QDebug>
#include "data_types.h"
#include "error_handling.h"
#include "paths.h"

PatientList::PatientList(QWidget *parent) : QMainWindow(parent), m_table_model(nullptr) {
	ui.setupUi(this);
	ErrorType error;
	CsvLoader::LoadAllPersons(getPersonsFilePath().toStdString(), m_patients, m_doctors, error);
	ErrorHandling::ReportError(error, "PatientList - Constructor");
	m_table_model = new QStandardItemModel(this);
	m_filter_model = new PatientFilterModel(this);

	ui.patientView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.patientView->setSortingEnabled(true);
	ui.patientView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	m_filter_model->setSourceModel(m_table_model);
	ui.patientView->setModel(m_filter_model);

	fillTable();

	connect(ui.testresultBox, &QComboBox::currentTextChanged,  m_filter_model, &PatientFilterModel::setOption);
	connect(ui.searchEdit, &QLineEdit::textEdited,  m_filter_model, &PatientFilterModel::setSearch);
	connect(ui.patientView, &QTableView::doubleClicked, this, &PatientList::onPatientDoubleClicked);

}

void PatientList::fillTable() {
	m_table_model->setColumnCount(3);
	m_table_model->setHorizontalHeaderLabels({ "Patient", "Positive", "Last test" });
	for (const auto& patient : m_patients) {

			QList<QStandardItem*> row;
			auto fullname = new QStandardItem(QString::fromStdString(patient->getSurname() + " " + patient->getName()));
			fullname->setFlags(fullname->flags() & ~Qt::ItemIsEditable);
			auto positive = new QStandardItem(patient->isPositive() ? "Yes" : "No");
			positive->setFlags(positive->flags() & ~Qt::ItemIsEditable);
			auto last_test_date = new QStandardItem(QString::fromStdString(patient->getLastTestDate()));
			last_test_date->setFlags(last_test_date->flags() & ~Qt::ItemIsEditable);
			row << fullname <<  positive << last_test_date;
			m_table_model->appendRow(row);
	}
	
}

void PatientList::onPatientDoubleClicked(const QModelIndex& _index) {
	if (!_index.isValid()) {
		//error
		return;
	}

	QModelIndex source_index = m_filter_model->mapToSource(_index); //Trought the connector you get an index from the filter model but because of sorting/filtering this does not necessarily correspond to the correct index from the source model(m_table_model)
	int row_number = source_index.row();
	
	if (row_number >= 0 && row_number < m_patients.size()) {
		Patient* patient = (m_patients[row_number].get()); //Get patient out of patient vector
		if (patient) {
			m_patient_details = new PatientDetails(patient, this);
			m_patient_details->exec();
		}
	}
}


void PatientList::on_addpatientButton_clicked() {
	AddPatient addpatient;
	connect(&addpatient, &AddPatient::patientAdded, this, &PatientList::addPatientToList);
	addpatient.exec();
}

void PatientList::on_removepatientButton_clicked() {
	QModelIndex selected_index = ui.patientView->selectionModel()->currentIndex();
	if (!selected_index.isValid()) {
		QMessageBox::warning(this, "No selection", "Please select a patient"); 
		return;
	}

	QModelIndex source_index = m_filter_model->mapToSource(selected_index);
	int row_number = source_index.row();
	ErrorType error;

	if (row_number >= 0 && row_number < m_patients.size()) {
		m_patients.erase(m_patients.begin() + row_number); //.begin is nodig omdat .erase een iterator gebruikt en niet gewoon een index .begin geeft de iterator van het begin van de vector en row_number verhooogt deze dan tot naar de juiste patient gewezen wordt
		m_table_model->removeRow(row_number);

		CsvLoader::SaveAllPersons(m_patients, m_doctors, "Data/persons.csv", error);
	}

	ErrorHandling::ReportError(error, "PatientList - on_removepatientButton_clicked]");

}

void PatientList::addPatientToList(Patient* _new_patient) {
		QList<QStandardItem*> row;
		auto fullname = new QStandardItem(QString::fromStdString(_new_patient->getSurname() + " " + _new_patient->getName()));
		fullname->setFlags(fullname->flags() & ~Qt::ItemIsEditable);
		auto positive = new QStandardItem(_new_patient->isPositive() ? "Yes" : "No");
		positive->setFlags(positive->flags() & ~Qt::ItemIsEditable);
		auto last_test_date = new QStandardItem(QString::fromStdString(_new_patient->getLastTestDate()));
		last_test_date->setFlags(last_test_date->flags() & ~Qt::ItemIsEditable);
		row << fullname <<  positive << last_test_date;
		m_table_model->appendRow(row);
		
		m_patients.push_back(std::unique_ptr<Patient>(_new_patient));
}


PatientList::~PatientList() {
}
