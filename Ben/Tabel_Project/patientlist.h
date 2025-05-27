#pragma once

#include "ui_patientlist.h"
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include "person.h"
#include "patientfilltermodel.h"
#include "patientdetails.h"

class PatientList : public QMainWindow
{
	Q_OBJECT

public:
	PatientList(QWidget *parent = Q_NULLPTR);
	~PatientList();
private slots:
	void onPatientClicked(const QModelIndex& _index);
private:
	Ui::PatientList ui;
	std::vector<std::unique_ptr<Person>> patients;
	QStandardItemModel* m_table_model;
	PatientFilterModel* m_filter_model;
	PatientDetails* m_patient_details;
	QString m_current_search;
	QString m_current_option;
	void fillTable();
};



