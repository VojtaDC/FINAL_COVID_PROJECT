#pragma once


#include "person.h"


class Patient : public Person {
private:
	bool positive;
	std::string lastTestDate;
public:
	Patient(const std::string& name, const std::string& surname, const std::string& password, const std::string& phoneNumber,
		const std::string& email, bool positive, const std::string& lastTestDate);
	bool getPositive();
	std::string getLastTestDate();
	void setLastTestDate(const std::string& newTestDate);
	void setPositive(bool newResult);
	
};
