#pragma once


#include "person.h"

class Doctor : public Person {
private:
	std::string specialization;

public:
	Doctor(const std::string& name, const std::string& surname, const std::string& password, const std::string& phoneNumber, const std::string& email,
		const std::string& specialization);
	std::string getSpecialization() const;
	void setSpecialization(const std::string& newSpecialization);
	
};
