#include "doctor.h"
#include <iostream>

Doctor::Doctor(const std::string& _name, const std::string& _surname, const std::string& _password, const std::string& _phoneNumber, const std::string& _email,
	const std::string& _specialization)
	: Person(_name, _surname, _password, _phoneNumber, _email), m_specialization(_specialization) {}

std::string Doctor::getSpecialization() const {
	return m_specialization;
}

void Doctor::setSpecialization(const std::string& _newSpecialization) {
	m_specialization = _newSpecialization;
}

Doctor::~Doctor() {
}



