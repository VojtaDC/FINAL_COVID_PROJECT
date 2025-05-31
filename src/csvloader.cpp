#include <fstream>
#include <string>
#include "csvloader.h"
#include <sstream>
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <functional>
#include <QDebug>

// New type-based implementation
void CsvLoader::LoadAllPersons(const std::string& _filepath, std::vector<std::unique_ptr<Patient>>& _patients, std::vector<std::unique_ptr<Doctor>>& _doctors) {
	std::vector<std::unique_ptr<Person>> persons;
	std::ifstream file(_filepath);

	// _error = ErrorType::No_Error;

	if (!file.is_open()) {
		// _error = ErrorType::File_Open_Failed;
		return;
	}

	std::string line;
	std::getline(file, line); // Skip header

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::vector<std::string> fields;
		std::string field;

		while (std::getline(ss, field, ';')) { // Using semicolon separator
			fields.push_back(field);
		}
        // Check number of fields to make sure we have enough data
        if (fields.size() < 7) { // At least 7 fields needed for Doctor
            qDebug() << "Skipping line with insufficient fields:" << QString::fromStdString(line);
            continue;
        }

        qDebug() << "Processing line:" << QString::fromStdString(line);
        qDebug() << "Field type:" << QString::fromStdString(fields[0]);
		if (fields[0] == "Doctor") {

			std::unique_ptr<Doctor> doctor = std::make_unique<Doctor>(fields[1], fields[2], fields[3], fields[4], fields[5], fields[6]);
			_doctors.push_back(std::move(doctor));
        
		}
		else if (fields[0] == "Patient") {
			bool isPositive = (fields[7] == "true");
			std::unique_ptr<Patient> patient = std::make_unique<Patient>(fields[1], fields[2], fields[3], fields[4], fields[5], isPositive, fields[8]);
			_patients.push_back(std::move(patient));
            qDebug() << "Processing line:" << QString::fromStdString(line);
            qDebug() << "Field type:" << QString::fromStdString(fields[0]);

		// }
		// else {
		// 	_error = ErrorType::Wrong_Type;
		// }
	}
	
    }
	return;
}

void CsvLoader::SavePatients(const std::vector<std::unique_ptr<Person>>& _patients, const std::string& _filepath) {
	std::ofstream m_fileStream;
	m_fileStream.open(_filepath);
	if (m_fileStream.is_open())
	{
		m_fileStream << "type;name;surname;password;phoneNumber;email;positive;last_test_date" << std::endl;
		for (const auto& m_p : _patients) {
			const Patient* m_patient = dynamic_cast<const Patient*>(m_p.get());
			if (m_patient) {
				m_fileStream << "Patient" << ";"
					<< m_patient->getName() << ";"
					<< m_patient->getSurname() << ";"
					<< m_patient->getPassword() << ";"
					<< m_patient->getPhoneNumber() << ";"
					<< m_patient->getEmail() << ";"
					<< (m_patient->isPositive() ? "true" : "false") << ";"
					<< m_patient->getLastTestDate()
					<< std::endl;
			}
		}
		m_fileStream.close();
	}
}

void CsvLoader::SaveAllPersons(const std::vector<std::unique_ptr<Person>>& _persons, const std::string& _filepath) {
	std::ofstream m_fileStream;
	m_fileStream.open(_filepath);
	if (m_fileStream.is_open())
	{
		m_fileStream << "type;name;surname;password;phoneNumber;email;specialization;positive;last_test_date" << std::endl;
		for (const auto& person : _persons) {
			if (const Patient* patient = dynamic_cast<const Patient*>(person.get())) {
				m_fileStream << "Patient" << ";"
					<< patient->getName() << ";"
					<< patient->getSurname() << ";"
					<< patient->getPassword() << ";"
					<< patient->getPhoneNumber() << ";"
					<< patient->getEmail() << ";"
					<< ";" // empty specialization for patients
					<< (patient->isPositive() ? "true" : "false") << ";"
					<< patient->getLastTestDate()
					<< std::endl;
			}
			else if (const Doctor* doctor = dynamic_cast<const Doctor*>(person.get())) {
				m_fileStream << "Doctor" << ";"
					<< doctor->getName() << ";"
					<< doctor->getSurname() << ";"
					<< doctor->getPassword() << ";"
					<< doctor->getPhoneNumber() << ";"
					<< doctor->getEmail() << ";"
					<< doctor->getSpecialization() << ";"
					<< "false" << ";" // doctors don't have positive status
					<< "N/A" // doctors don't have test dates
					<< std::endl;
			}
		}
		m_fileStream.close();
	}
}
