#include <fstream>
#include <string>
#include "csvloader.h"
#include <sstream>
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <functional>



// New type-based implementation
std::vector<std::unique_ptr<Person>> CsvLoader::LoadAllPersons(const std::string& _filepath) {
    std::vector<std::unique_ptr<Person>> persons;
    std::ifstream file(_filepath);
    
    if (!file.is_open()) {
        std::cerr << "[CsvLoader] Kan bestand niet openen: " << _filepath << "\n";
        return persons;
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
        
        if (auto person = CreatePersonFromData(fields)) {
            persons.push_back(std::move(person));
            
        }
    }
    
    return persons;
}

std::unique_ptr<Person> CsvLoader::CreatePersonFromData(const std::vector<std::string>& _data) {
    if (_data.size() < 6) {
        std::cerr << "[CsvLoader] Onvoldoende data in rij\n";
        return nullptr;
    }
    
    const std::string& type = _data[0];
    
    if (type == "Doctor") {
        if (_data.size() < 7) return nullptr;
                return std::make_unique<Doctor>(
            _data[1], _data[2], _data[3], _data[4], _data[5], _data[6]
        );
    }
    else if (type == "Patient") {
        if (_data.size() < 9) return nullptr;
        bool isPositive = (_data[7] == "true");
        return std::make_unique<Patient>(
            _data[1], _data[2], _data[3], _data[4], _data[5], isPositive, _data[8]
        );
    }
    else {
        std::cerr << "[CsvLoader] Onbekend type: " << type << "\n";
        return nullptr;
    }
}

std::vector<std::unique_ptr<Doctor>> CsvLoader::FilterDoctors(const std::vector<std::unique_ptr<Person>>& _persons) {
    std::vector<std::unique_ptr<Doctor>> doctors;
    
    for (const auto& person : _persons) {
        if (Doctor* doctor = dynamic_cast<Doctor*>(person.get())) {
            doctors.push_back(std::make_unique<Doctor>(
                doctor->getName(),
                doctor->getSurname(),
                doctor->getPassword(),
                doctor->getPhoneNumber(),
                doctor->getEmail(),
                doctor->getSpecialization()
            ));
        }
    }
    
    return doctors;
}

std::vector<std::unique_ptr<Patient>> CsvLoader::FilterPatients(const std::vector<std::unique_ptr<Person>>& _persons) {
    std::vector<std::unique_ptr<Patient>> patients;
    
    for (const auto& person : _persons) {
        if (Patient* patient = dynamic_cast<Patient*>(person.get())) {
            patients.push_back(std::make_unique<Patient>(
                patient->getName(),
                patient->getSurname(),
                patient->getPassword(),
                patient->getPhoneNumber(),
                patient->getEmail(),
                patient->isPositive(),
                patient->getLastTestDate()
            ));
        }
    }
    
    return patients;
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
