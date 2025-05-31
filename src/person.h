#pragma once

#include <string>

class Person {
protected:
	std::string m_name;
	std::string m_surname;
	std::string m_ID;
	std::string m_email;
	std::string m_phoneNumber;
	std::string m_password;

public:
	Person(const std::string& _name, const std::string& _surname, const std::string& _password, const std::string& _phoneNumber, const std::string& _email);
	std::string getName() const;
	std::string getSurname() const;
	std::string getPassword() const;
	std::string getEmail() const;
	std::string getPhoneNumber() const;
	void setName(const std::string& _newName);
	void setSurname(const std::string& _newSurname);
	void setPassword(const std::string& _newPassword);
	void setPhoneNumber(const std::string& _newPhoneNumber);
	void setEmail(const std::string& _newEmail);
	virtual ~Person();
};

