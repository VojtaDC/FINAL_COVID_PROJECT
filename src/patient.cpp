#include "patient.h"
#include <iostream>

Patient::Patient(const std::string& _name, const std::string& _surname, const std::string& _password, const std::string& _phoneNumber, const std::string& _email, bool _positive, const std::string& _lastTestDate)
	: Person(_name, _surname, _password, _phoneNumber, _email), m_positive(_positive), m_lastTestDate(_lastTestDate) {}


bool Patient::isPositive() const {
	return m_positive;
}

std::string Patient::getLastTestDate() const {
	return m_lastTestDate;
}

void Patient::setLastTestDate(const std::string& _newLastTestDate) {
	m_lastTestDate = _newLastTestDate;
}

void Patient::setPositive(bool _newResult) {
	m_positive = _newResult;
}

Patient::~Patient() {
}
