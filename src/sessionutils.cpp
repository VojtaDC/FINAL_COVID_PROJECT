#include "sessionutils.h"
#include "loginscreen.h"
#include <QApplication>


// Statische variabele initialiseren
Patient* sessionutils::currentPatient = nullptr;
Doctor* sessionutils::currentDoctor = nullptr;

// Implementatie van eventuele niet-template methoden
void sessionutils::performSignOff(QWidget* widget) {
    if (widget) {
        LoginScreen* loginScreen = new LoginScreen();
        loginScreen->show();
        widget->close();
    }
    // Reset de huidige sessiegegevens
    setCurrentPatient(nullptr);
    setCurrentDoctor(nullptr);
}

void sessionutils::setCurrentPatient(Patient* patient) {
    currentPatient = patient;
    currentDoctor = nullptr;
}

Patient* sessionutils::getCurrentPatient() {
    return currentPatient;
}

void sessionutils::setCurrentDoctor(Doctor* doctor) {
    currentDoctor = doctor;
    currentPatient = nullptr; // Reset patiënt als een doctor inlogt
}

Doctor* sessionutils::getCurrentDoctor() {
    return currentDoctor;
}

QString sessionutils::getCurrentUserFirstName() {
    if (currentPatient) {
        return QString::fromStdString(currentPatient->getName());
    }
    else if (currentDoctor) {
        return QString::fromStdString(currentDoctor->getName());
    }
    return "Unknown";
}