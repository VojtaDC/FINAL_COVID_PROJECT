#pragma once


#include "person.h"


class Patient : public Person {
private:
	bool m_positive;
	std::string m_lastTestDate;
public:
	Patient(const std::string& _name, const std::string& _surname, const std::string& _password, const std::string& _phoneNumber,
		const std::string& _email, bool _positive, const std::string& _lastTestDate);
	bool isPositive() const;
	std::string getLastTestDate() const;
	void setLastTestDate(const std::string& _newTestDate);
	void setPositive(bool _newResult);
	~Patient() override;
};
