#include <fstream>
#include <string>
#include "csvloader.h"
#include <sstream>
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <functional>

// Legacy method implementation (maintained for backward compatibility)
std::vector<std::unique_ptr<Person>> CsvLoader::loadPersons(const std::string& filepath, const std::string& doctor_or_patient) {
	std::vector<std::unique_ptr<Person>> people;
	std::ifstream file_stream_read;
	file_stream_read.open(filepath);
	std::string line;
	if (file_stream_read.is_open()) {
		std::getline(file_stream_read, line); //This puts the header of the csv file in line so it is skipped
		while (std::getline(file_stream_read, line)) {
			std::stringstream line_read(line);
			std::vector<std::string> parameters;

			std::string parameter;
			while (std::getline(line_read, parameter, ';')) {
				parameters.push_back(parameter);
			}
			if (doctor_or_patient == "doctor") {
				//Doctor CSV structure: name,surname,password,phoneNumber,email,speciliazisiton
				people.push_back(std::make_unique<Doctor>(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], parameters[5]));
			}

			else if (doctor_or_patient == "patient") {
				//Patient CSV structure: name,surname,password,phoneNumber,email,positive,last_test_date
				bool isPositive = (parameters[5] == "true"); //Van string naar bool
				people.push_back(std::make_unique<Patient>(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4], isPositive, parameters[6]));
			}

			else {
				std::cerr << "[CsvLoader] Ongeldig type: " << doctor_or_patient << "\n";
			}
		}
	}
	else {
		std::cerr << "[CsvLoader] Kan bestand niet openen: " << filepath << "\n";
	}
	return people;
}

// New template-based implementation
template<typename T>
std::vector<std::unique_ptr<T>> CsvLoader::load(
    const std::string &filepath,
    std::function<std::unique_ptr<T>(const std::vector<std::string>&)> factory)
{
    std::vector<std::unique_ptr<T>> result;
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "[CsvLoader] Kan bestand niet openen: " << filepath << "\n";
        return result;
    }

    std::string line;
    std::getline(file, line);  // header overslaan

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> cols;
        std::string field;
        while (std::getline(ss, field, ';'))
            cols.push_back(field);
        // Vraag de factory om het juiste object (Doctor of Patient) te maken
        if (auto obj = factory(cols))
            result.push_back(std::move(obj));
    }
    return result;
}

// De template definities moeten expliciet worden geïnstantieerd
template std::vector<std::unique_ptr<Doctor>> CsvLoader::load<Doctor>(
    const std::string&, std::function<std::unique_ptr<Doctor>(const std::vector<std::string>&)>);
template std::vector<std::unique_ptr<Patient>> CsvLoader::load<Patient>(
    const std::string&, std::function<std::unique_ptr<Patient>(const std::vector<std::string>&)>);
