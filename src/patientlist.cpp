#include "patientlist.h"
#include "csvloader.h"
#include "addpatient.h"
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>
#include <QHeaderView>
#include <QTableView>
#include <QDir>
#include <QMessageBox>
#include "paths.h"


PatientList::PatientList(QWidget *parent) : QMainWindow(parent), m_table_model(nullptr) {	
	ui.setupUi(this);
	
	// Use the file-based approach
	QDir exeDir(QCoreApplication::applicationDirPath()); 
    exeDir.cdUp();             
    exeDir.cd("data");
    QString personsFile = getPersonsFilePath();    // Laad alle personen uit één bestand met de nieuwe type-gebaseerde methode
    m_all_persons = CsvLoader::LoadAllPersons(personsFile.toStdString());
	
    // Use the filter method from CsvLoader instead of manual filtering
    auto filtered_patients = CsvLoader::FilterPatients(m_all_persons);
	
	// Initialize table model and filter
	m_table_model = new QStandardItemModel(this);
	m_filter_model = new PatientFilterModel(this);

	ui.patientView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.patientView->setSortingEnabled(true);
	ui.patientView->setEditTriggers(QAbstractItemView::NoEditTriggers);

	m_filter_model->setSourceModel(m_table_model);
	ui.patientView->setModel(m_filter_model);

	fillTable();

	
	connect(ui.testresultBox, &QComboBox::currentTextChanged, m_filter_model, &PatientFilterModel::setOption);
	connect(ui.searchEdit, &QLineEdit::textEdited, m_filter_model, &PatientFilterModel::setSearch);
	connect(ui.patientView, &QTableView::doubleClicked, this, &PatientList::onPatientDoubleClicked);
	
	// Debug output
	qDebug() << "Loaded" << m_patients.size() << "patients";
}

void PatientList::fillTable() {
	m_table_model->setColumnCount(3);
	m_table_model->setHorizontalHeaderLabels({ "Patient", "Positive", "Last test" });
	qDebug() << "Filling table with" << m_patients.size() << "patients";
	for (const auto& p : m_patients) {
		if (Patient* patient = dynamic_cast<Patient*>(p.get())) { //p.get returns a raw pointer but this pointer is still owned by the std::unique_ptr so destructor should not be called
			QList<QStandardItem*> row;
			auto fullname = new QStandardItem(QString::fromStdString(patient->getSurname() + " " + patient->getName()));
			fullname->setFlags(fullname->flags() & ~Qt::ItemIsEditable);
			auto positive = new QStandardItem(patient->isPositive() ? "Yes" : "No");
			positive->setFlags(positive->flags() & ~Qt::ItemIsEditable);
			auto last_test_date = new QStandardItem(QString::fromStdString(patient->getLastTestDate()));
			last_test_date->setFlags(last_test_date->flags() & ~Qt::ItemIsEditable);
			row << fullname << positive << last_test_date;
			m_table_model->appendRow(row);
			qDebug() << "Added patient:" << QString::fromStdString(patient->getName() + " " + patient->getSurname());
		}
		else {
			//error geen patient object
		}
	}
}

void PatientList::onPatientDoubleClicked(const QModelIndex& _index) {
	if (!_index.isValid()) {
		//error
		return;
	}
	QModelIndex source_index = m_filter_model->mapToSource(_index); //Trought the connector you get an index from the filter model but because of sorting/filtering this does not necessarily correspond to the correct index from the source model(m_table_model)
	int row_number = source_index.row();
	
	if (row_number >= 0 && static_cast<size_t>(row_number) < m_patients.size()) {
		Patient* patient = dynamic_cast<Patient*>(m_patients[row_number].get()); //Get patient out of patient vector
		if (patient) {
			m_patient_details = new PatientDetails(patient, this);
			m_patient_details->exec();
		}
	}
}

void PatientList::on_addpatientButton_clicked() {
	AddPatient addpatient;
	disconnect(&addpatient, &AddPatient::patientAdded, nullptr, nullptr); // Clear any existing connections
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

	if (row_number >= 0 && row_number < m_patients.size()) {
		m_patients.erase(m_patients.begin() + row_number); //.begin is nodig omdat .erase een iterator gebruikt en niet gewoon een index .begin geeft de iterator van het begin van de vector en row_number verhooogt deze dan tot naar de juiste patient gewezen wordt
		m_table_model->removeRow(row_number);

		CsvLoader::SavePatients(m_patients, getPersonsFilePath().toStdString());
	}

}

void PatientList::addPatientToList(Patient* _new_patient) {
		QList<QStandardItem*> row;
		auto fullname = new QStandardItem(QString::fromStdString(_new_patient->getSurname() + " " + _new_patient->getName()));
		fullname->setFlags(fullname->flags() & ~Qt::ItemIsEditable);
		auto positive = new QStandardItem(_new_patient->isPositive() ? "Yes" : "No");
		positive->setFlags(positive->flags() & ~Qt::ItemIsEditable);
		auto last_test_date = new QStandardItem(QString::fromStdString(_new_patient->getLastTestDate()));
		last_test_date->setFlags(last_test_date->flags() & ~Qt::ItemIsEditable);
		row << fullname << positive << last_test_date;
		m_table_model->appendRow(row);
		
		m_patients.push_back(std::unique_ptr<Person>(_new_patient));
}

PatientList::~PatientList() {
}