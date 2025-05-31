#include "person.h"
#include <iostream>

Person::Person(const std::string& _name, const std::string& _surname, const std::string& _password, const std::string& _phoneNumber, const std::string& _email)
	: m_name(_name), m_surname(_surname), m_password(_password), m_phoneNumber(_phoneNumber), m_email(_email) {}

std::string Person::getName() const {
	return m_name;
}

std::string Person::getSurname() const {
	return m_surname;
}

std::string Person::getPassword() const {
	return m_password;
}

std::string Person::getPhoneNumber() const {
	return m_phoneNumber;
}

std::string Person::getEmail() const {
	return m_email;
}

void Person::setName(const std::string& _newName) {
	m_name = _newName;
}

void Person::setSurname(const std::string& _newSurname) {
	m_surname = _newSurname;
}

void Person::setPassword(const std::string& _newPassword) {
	m_password = _newPassword;
}

void Person::setPhoneNumber(const std::string& _newPhoneNumber) {
	m_phoneNumber = _newPhoneNumber;
}

void Person::setEmail(const std::string& _newEmail) {
	m_email = _newEmail;
}

Person::~Person() {
}
