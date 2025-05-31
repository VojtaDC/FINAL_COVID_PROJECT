#pragma once

#include <QWidget>
#include "patient.h"
#include "doctor.h"

// Forward declaration om circulaire includes te voorkomen
class LoginScreen;

class SessionUtils {
public:
	// Reguliere functie in plaats van template functie
	static void PerformSignOff(QWidget* widget);

	// Patient management
	static void SetCurrentPatient(Patient* patient);
	static Patient* GetCurrentPatient();

	static void SetCurrentDoctor(Doctor* doctor);
	static Doctor* GetCurrentDoctor();

	static QString GetCurrentUserFirstName();  // Deze naam moet overeenkomen met de implementatie

private:
	static Patient* m_current_patient;
	static Doctor* m_current_doctor;
};
