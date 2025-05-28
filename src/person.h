#pragma once

#include <string>

class Person {
protected:      // Only accessible in this class and derived classes
	std::string name;
	std::string surname;
	std::string ID;
	std::string email;
	std::string phoneNumber;
	std::string password;

public:
	Person(const std::string& name, const std::string& surname, const std::string& password, const std::string& phoneNumber, const std::string& email);
	virtual ~Person() = default;  // Make Person polymorphic
	std::string getName() const;
	std::string getSurname() const;
	std::string getPassword() const;
	std::string getEmail() const;
	std::string getPhoneNumber() const;
	void setName(const std::string& newName);
	void setSurname(const std::string& newSurname);
	void setPassword(const std::string& newPassword);
	void setPhoneNumber(const std::string& newPhoneNumber);
	void setEmail(const std::string& newEmail);
};

