#pragma once 
#include <QWidget>
#include "patient.h"
#include "doctor.h"

// Forward declaration om circulaire includes te voorkomen
class LoginScreen;

class sessionutils {
public:
    // Reguliere functie in plaats van template functie
    static void performSignOff(QWidget* widget);

    // Patiënt management
    static void setCurrentPatient(Patient* patient);
    static Patient* getCurrentPatient();

    static void setCurrentDoctor(Doctor* doctor);
    static Doctor* getCurrentDoctor();

    static QString getCurrentUserFirstName();

private:
    static Patient* currentPatient;
    static Doctor* currentDoctor;
};