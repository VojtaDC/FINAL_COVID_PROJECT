#pragma once

#include <QDialog>
#include <QStandardItemModel>
#include "patient.h"
#include "ui_patientdetails.h"

class PatientDetails : public QDialog {
	Q_OBJECT

public:
	PatientDetails(Patient* patient, QWidget *parent = nullptr);
	~PatientDetails();

private:
	Ui::PatientDetails ui;
	QStandardItemModel* m_table_model;
};
