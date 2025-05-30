#pragma once

#include <string>

class Person {
protected:      // Only accessible in this class and derived classes
	std::string m_name;
	std::string m_surname;
	std::string m_password;
	std::string m_phoneNumber;
	std::string m_email;

public:
	Person(const std::string& _name, const std::string& _surname, const std::string& _password, const std::string& _phoneNumber, const std::string& _email);
	virtual ~Person();
	std::string getName() const;
	std::string getSurname() const;
	std::string getPassword() const;
	std::string getPhoneNumber() const;
	std::string getEmail() const;
	void setName(const std::string& _newName);
	void setSurname(const std::string& _newSurname);
	void setPassword(const std::string& _newPassword);
	void setPhoneNumber(const std::string& _newPhoneNumber);
	void setEmail(const std::string& _newEmail);
};

