#pragma once
#include "ui_patientlist.h"
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include "person.h"
#include "patient.h"
#include "patientfiltermodel.h"
#include "patientdetails.h"

class PatientList : public QMainWindow
{
	Q_OBJECT

public:
	PatientList(QWidget *parent = Q_NULLPTR);
	~PatientList();
	
private slots:
	void onPatientDoubleClicked(const QModelIndex& _index);
	void on_addpatientButton_clicked();
	void on_removepatientButton_clicked();
	void addPatientToList(Patient* _new_patient);

private:
	Ui::PatientList ui;
	std::vector<std::unique_ptr<Person>> m_patients;
	std::vector<std::unique_ptr<Person>> m_all_persons; // Store all persons (doctors + patients)
	QStandardItemModel* m_table_model;
	PatientFilterModel* m_filter_model;
	PatientDetails* m_patient_details;
	QString m_current_search;
	QString m_current_option;
	void fillTable();
};



