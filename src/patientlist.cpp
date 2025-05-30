#include "patientlist.h"
#include "csvloader.h"
#include <QDebug>
#include <QComboBox>
#include <QLineEdit>
#include <QHeaderView>
#include <QTableView>
#include <QDir>

PatientList::PatientList(QWidget *parent) : QMainWindow(parent), m_table_model(nullptr) {	
	ui.setupUi(this);
	
	// Use the new type-based approach
	QDir exeDir(QCoreApplication::applicationDirPath()); 
    exeDir.cdUp();             
    exeDir.cd("data");
    QString personsFile = exeDir.filePath("persons.csv");

    // Laad alle personen uit één bestand met de nieuwe type-gebaseerde methode
    auto allPersons = CsvLoader::loadAllPersons(personsFile.toStdString());
	
	// Convert specific patients to Person pointers
	for (const auto& person : allPersons) {
		if (dynamic_cast<Patient*>(person.get())) {
			// Move the Patient from allPersons to patients vector
			patients.push_back(std::move(const_cast<std::unique_ptr<Person>&>(person)));
		}
	}
	
	// Initialize table model and filter
	m_table_model = new QStandardItemModel(this);
	m_filter_model = new PatientFilterModel(this);

	ui.patientView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.patientView->setSortingEnabled(true);

	m_filter_model->setSourceModel(m_table_model);
	ui.patientView->setModel(m_filter_model);
	ui.patientView->setEditTriggers(QAbstractItemView::NoEditTriggers); // make read-only


	fillTable();
	// Connect signals - UI elements exist now
	connect(ui.testresultBox, &QComboBox::currentTextChanged, m_filter_model, &PatientFilterModel::setOption);
	connect(ui.searchEdit, &QLineEdit::textEdited, m_filter_model, &PatientFilterModel::setSearch);
	connect(ui.patientView, &QTableView::clicked, this, &PatientList::onPatientClicked);
	
	// Debug output
	qDebug() << "Loaded" << patients.size() << "patients";
}

void PatientList::fillTable() {
	m_table_model->setColumnCount(3);
	m_table_model->setHorizontalHeaderLabels({ "Patient", "Positive", "Last test" });
	qDebug() << "Filling table with" << patients.size() << "patients";
	for (const auto& p : patients) {
		if (Patient* patient = dynamic_cast<Patient*>(p.get())) {
			QList<QStandardItem*> row;
			auto fullname = new QStandardItem(QString::fromStdString(patient->getSurname() + " " + patient->getName()));
			auto positive = new QStandardItem(patient->getPositive() ? "Yes" : "No"); // Fixed: use getPositive() instead of isPositive()
			auto last_test_date = new QStandardItem(QString::fromStdString(patient->getLastTestDate()));
			row << fullname << positive << last_test_date;
			m_table_model->appendRow(row);
			qDebug() << "Added patient:" << QString::fromStdString(patient->getName() + " " + patient->getSurname());
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

	QModelIndex source_index = m_filter_model->mapToSource(_index);
	int row_number = source_index.row();
	
	if (row_number >= 0 && static_cast<size_t>(row_number) < patients.size()) {
		Patient* patient = dynamic_cast<Patient*>(patients[row_number].get());
		if (patient) {
			m_patient_details = new PatientDetails(patient, this);
			m_patient_details->exec();
		}
	}
}

PatientList::~PatientList() {
}
