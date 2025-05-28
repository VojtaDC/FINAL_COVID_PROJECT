#include <fstream>
#include <string>
#include "csvloader.h"
#include <sstream>
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <functional>


// New type-based implementation
std::vector<std::unique_ptr<Person>> CsvLoader::loadAllPersons(const std::string& filepath) {
    std::vector<std::unique_ptr<Person>> persons;
    std::ifstream file(filepath);
    
    if (!file.is_open()) {
        std::cerr << "[CsvLoader] Kan bestand niet openen: " << filepath << "\n";
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
        
        if (auto person = createPersonFromData(fields)) {
            persons.push_back(std::move(person));
        }
    }
    
    return persons;
}

std::unique_ptr<Person> CsvLoader::createPersonFromData(const std::vector<std::string>& data) {
    if (data.size() < 6) {
        std::cerr << "[CsvLoader] Onvoldoende data in rij\n";
        return nullptr;
    }
    
    const std::string& type = data[0];
    
    if (type == "Doctor") {
        if (data.size() < 7) return nullptr;
        // type;name;surname;password;phoneNumber;email;specialization;positive;last_test_date
        return std::make_unique<Doctor>(
            data[1], data[2], data[3], data[4], data[5], data[6]
        );
    }
    else if (type == "Patient") {
        if (data.size() < 9) return nullptr;
        // type;name;surname;password;phoneNumber;email;specialization;positive;last_test_date
        bool isPositive = (data[7] == "true");
        return std::make_unique<Patient>(
            data[1], data[2], data[3], data[4], data[5], isPositive, data[8]
        );
    }
    else {
        std::cerr << "[CsvLoader] Onbekend type: " << type << "\n";
        return nullptr;
    }
}

std::vector<std::unique_ptr<Doctor>> CsvLoader::filterDoctors(const std::vector<std::unique_ptr<Person>>& persons) {
    std::vector<std::unique_ptr<Doctor>> doctors;
    
    for (const auto& person : persons) {
        if (Doctor* doctor = dynamic_cast<Doctor*>(person.get())) {
            // Create a copy of the doctor
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

std::vector<std::unique_ptr<Patient>> CsvLoader::filterPatients(const std::vector<std::unique_ptr<Person>>& persons) {
    std::vector<std::unique_ptr<Patient>> patients;
    
    for (const auto& person : persons) {
        if (Patient* patient = dynamic_cast<Patient*>(person.get())) {
            // Create a copy of the patient
            patients.push_back(std::make_unique<Patient>(
                patient->getName(),
                patient->getSurname(),
                patient->getPassword(),
                patient->getPhoneNumber(),
                patient->getEmail(),
                patient->getPositive(),
                patient->getLastTestDate()
            ));
        }
    }
    
    return patients;
}
