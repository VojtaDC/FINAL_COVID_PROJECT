#include "doctor.h"
#include <iostream>

Doctor::Doctor(const std::string& name, const std::string& surname, const std::string& password, const std::string& phoneNumber, const std::string& email,
	const std::string& specialization)
	: Person(name, surname, password, phoneNumber, email), specialization(specialization) {}

std::string Doctor::getSpecialization() const {
	return specialization;
}


void Doctor::setSpecialization(const std::string& newSpecialization) {
	specialization = newSpecialization;
}


