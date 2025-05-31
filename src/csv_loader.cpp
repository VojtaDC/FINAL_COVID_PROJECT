#include <fstream>
#include <string>
#include "csv_loader.h"
#include <sstream>
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <functional>


// New type-based implementation
void CsvLoader::LoadAllPersons(const std::string& _filepath, std::vector<std::unique_ptr<Patient>>& _patients, std::vector<std::unique_ptr<Doctor>>& _doctors, ErrorType& _error) {
	std::vector<std::unique_ptr<Person>> persons;
	std::ifstream file_stream;
	file_stream.open(_filepath);

	_error = ErrorType::No_Error;

	if (!file_stream.is_open()) {
		_error = ErrorType::File_Open_Failed;
		return;
	}

	std::string line;
	std::getline(file_stream, line); // Skip header

	while (std::getline(file_stream, line)) {
		std::stringstream ss(line);
		std::vector<std::string> fields;
		std::string field;

		while (std::getline(ss, field, ';')) { // Using semicolon separator
			fields.push_back(field);
		}

		//Csv structure: Role;Name;Surname;Password;Phonenumber;Email;Specialiaztion;Positive;Last_test_date
		if (fields[0] == "Doctor") {
			std::unique_ptr<Doctor> doctor = std::make_unique<Doctor>(fields[1], fields[2], fields[3], fields[4], fields[5], fields[6]);
			_doctors.push_back(std::move(doctor));
		}
		else if (fields[0] == "Patient") {
			bool isPositive = (fields[7] == "true");
			std::unique_ptr<Patient> patient = std::make_unique<Patient>(fields[1], fields[2], fields[3], fields[4], fields[5], isPositive, fields[8]);
			_patients.push_back(std::move(patient));

		}
		else {
			_error = ErrorType::Wrong_Type;
		}
	}
	file_stream.close();

	return;
}


void CsvLoader::SaveAllPersons(const std::vector<std::unique_ptr<Patient>>& _patients, const std::vector<std::unique_ptr<Doctor>>& _doctors, const std::string& _filepath, ErrorType& _error) {
	std::ofstream file_stream;
	file_stream.open(_filepath);
	_error = ErrorType::No_Error;

	if (!file_stream.is_open())
		_error = ErrorType::File_Open_Failed;
		return;
	{
		file_stream << "type;name;surname;password;phoneNumber;email;specialization;positive;last_test_date" << std::endl;
		if (!file_stream) {
		_error = ErrorType::File_Write_Failed;
		return;
		}
		for (const auto& patient: _patients) {
			file_stream << "Patient" << ";"
				<< patient->getName() << ";"
				<< patient->getSurname() << ";"
				<< patient->getPassword() << ";"
				<< patient->getPhoneNumber() << ";"
				<< patient->getEmail() << ";"
				<< ";" // empty specialization for patients
				<< (patient->isPositive() ? "true" : "false") << ";"
				<< patient->getLastTestDate()
				<< std::endl;
			if (!file_stream) {
			_error = ErrorType::File_Write_Failed;
			return;
			}
		}
		for(const auto& doctor: _doctors) {
			file_stream << "Doctor" << ";"
				<< doctor->getName() << ";"
				<< doctor->getSurname() << ";"
				<< doctor->getPassword() << ";"
				<< doctor->getPhoneNumber() << ";"
				<< doctor->getEmail() << ";"
				<< doctor->getSpecialization() << ';'
				<< "N/A" << ";" // doctors don't have positive status
				<< "N/A" // doctors don't have test dates
				<< std::endl;
			if (!file_stream) {
			_error = ErrorType::File_Write_Failed;
			return;
			}
		}
	}
	file_stream.close();
	
}
