#pragma once

#include "person.h"

class Doctor : public Person {
private:
	std::string m_specialization;

public:
	Doctor(const std::string& _name, const std::string& _surname, const std::string& _password, const std::string& _phoneNumber, const std::string& _email,
		const std::string& _specialization);
	std::string getSpecialization() const;
	void setSpecialization(const std::string& _newSpecialization);
	~Doctor() override;
};
