#include "patient.h"
#include <iostream>

Patient::Patient(const std::string& name, const std::string& surname, const std::string& password, 
	const std::string& phoneNumber, const std::string& email, bool positive, const std::string& lastTestDate)
	: Person(name, surname, password, phoneNumber, email), positive(positive), lastTestDate(lastTestDate) {}


bool Patient::getPositive() {
	return positive;
}

std::string Patient::getLastTestDate() {
	return lastTestDate;
}

void Patient::setLastTestDate(const std::string& newLastTestDate) {
	lastTestDate = newLastTestDate;
}

void Patient::setPositive(bool newResult) {
	positive = newResult;
}
