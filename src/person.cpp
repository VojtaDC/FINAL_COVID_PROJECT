#include "person.h"
#include <iostream>

Person::Person(const std::string& name, const std::string& surname, const std::string& password, const std::string& phoneNumber, const std::string& email)
	: name(name), surname(surname), password(password), phoneNumber(phoneNumber), email(email) {}

std::string Person::getName() const {
	return name;
}

std::string Person::getSurname() const {
	return surname;
}


std::string Person::getPassword() const {
	return password;
}

std::string Person::getPhoneNumber() const {
	return phoneNumber;
}

std::string Person::getEmail() const {
	return email;
}
void Person::setName(const std::string& newName) {
	name = newName;
}

void Person::setSurname(const std::string& newSurname) {
	surname = newSurname;
}


void Person::setPassword(const std::string& newPassword) {
	password = newPassword;
}

void Person::setPhoneNumber(const std::string& newPhoneNumber) {
	phoneNumber = newPhoneNumber;
}

void Person::setEmail(const std::string& newEmail) {
	email = newEmail;
}
