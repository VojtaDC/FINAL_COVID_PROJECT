#include "sessionutils.h"
#include "loginscreen.h"
#include <QApplication>

// Statische variabele initialiseren
Patient* sessionutils::currentPatient = nullptr;

// Implementatie van eventuele niet-template methoden
void sessionutils::performSignOff(QWidget* widget) {
    if (widget) {
        LoginScreen* loginScreen = new LoginScreen();
        loginScreen->show();
        widget->close();
    }
    // Reset de huidige sessiegegevens
    setCurrentPatient(nullptr);
}

void sessionutils::setCurrentPatient(Patient* patient) {
    currentPatient = patient;
}

Patient* sessionutils::getCurrentPatient() {
    return currentPatient;
}