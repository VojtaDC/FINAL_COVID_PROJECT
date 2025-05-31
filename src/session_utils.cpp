#include "session_utils.h"
#include "login_screen.h"
#include <QApplication>


// Statische variabele initialiseren
Patient* SessionUtils::m_current_patient = nullptr;
Doctor* SessionUtils::m_current_doctor = nullptr;

// Implementatie van eventuele niet-template methoden
void SessionUtils::PerformSignOff(QWidget* widget) {
	if (widget) {
		LoginScreen* loginScreen = new LoginScreen();
		loginScreen->show();
		widget->close();
	}
	// Reset de huidige sessiegegevens
	SetCurrentPatient(nullptr);
	SetCurrentDoctor(nullptr);
}

void SessionUtils::SetCurrentPatient(Patient* patient) {
	m_current_patient = patient;
	m_current_doctor = nullptr;
}

Patient* SessionUtils::GetCurrentPatient() {
	return m_current_patient;
}

void SessionUtils::SetCurrentDoctor(Doctor* doctor) {
	m_current_doctor = doctor;
	m_current_patient = nullptr; // Reset patient als een doctor inlogt
}

Doctor* SessionUtils::GetCurrentDoctor() {
	return m_current_doctor;
}

QString SessionUtils::GetCurrentUserFirstName() {
	if (m_current_patient) {
		return QString::fromStdString(m_current_patient->getName());
	}
	else if (m_current_doctor) {
		return QString::fromStdString(m_current_doctor->getName());
	}
	return "Unknown";
}