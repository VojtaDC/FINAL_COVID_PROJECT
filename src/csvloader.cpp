#include <fstream>
#include <string>
#include "csvloader.h"
#include <sstream>
#include "doctor.h"
#include "patient.h"
#include <iostream> // Added for std::cout and std::endl

std::vector<std::unique_ptr<Person>> CsvLoader::loadPersons(const std::string& filepath, const std::string& doctor_or_patient) {
    std::cout << "[CsvLoader] Loading file: " << filepath << std::endl;
	std::vector<std::unique_ptr<Person>> people;
	std::ifstream file_stream_read;
	file_stream_read.open(filepath);
	std::string line;
	std::cout << "Line " << line << std::endl;
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
				bool isPositive = (parameters[6] == "true"); //Van string naar bool
				people.push_back(std::make_unique<Patient>(parameters[0], parameters[1],  parameters[2], parameters[3], parameters[4], isPositive, parameters[6]));
			}

			else {
				//error verkeerde input
			}
		}
	}
	else {
		//error file niet geopend
	}
	return people;
}
