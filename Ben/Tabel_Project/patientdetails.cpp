#include "patientdetails.h"

PatientDetails::PatientDetails(Patient* patient, QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
	int row_count = 6;
	m_table_model = new QStandardItemModel(row_count, 1, this);
	m_table_model->setVerticalHeaderLabels({ "Name", "Surname", "Email", "Phone", "Last result", "Last test date" });
	if (patient) { //kijken of patient geen nullptr is
		auto name = new QStandardItem(QString::fromStdString(patient->getName()));
		auto surname = new QStandardItem(QString::fromStdString(patient->getSurname()));
		auto email = new QStandardItem(QString::fromStdString(patient->getEmail()));
		auto phone = new QStandardItem(QString::fromStdString(patient->getPhoneNumber()));
		auto  positive = new QStandardItem((patient->isPositive() ? "Positve" : "Negative"));
		auto last_test_date = new QStandardItem(QString::fromStdString(patient->getLastTestDate()));

		m_table_model->setItem(0, 0, name);
		m_table_model->setItem(1, 0, surname);
		m_table_model->setItem(2, 0, email);
		m_table_model->setItem(3, 0, phone);
		m_table_model->setItem(4, 0, positive);
		m_table_model->setItem(5, 0, last_test_date);
	}

	ui.patientdetailsView->setModel(m_table_model);
	ui.patientdetailsView->horizontalHeader()->setVisible(false);
	ui.patientdetailsView->verticalHeader()->setDefaultSectionSize(25);
	ui.patientdetailsView->resizeColumnsToContents();
	ui.patientdetailsView->horizontalHeader()->setStretchLastSection(true);
	int table_height = ui.patientdetailsView->viewport()->height();
	int row_height = table_height / row_count;
	for (int row = 0; row < row_count; ++row) {
		ui.patientdetailsView->setRowHeight(row, row_height);
	}

}

PatientDetails::~PatientDetails() {
}