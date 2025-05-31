#pragma once

#include <vector>
#include <qsharedpointer.h>
#include <memory>
#include <functional>
#include <string>
#include "person.h"
#include "data_types.h"

// Forward declarations
class Doctor;
class Patient;

class CsvLoader {
public:

	// New type-based methods
	static void LoadAllPersons(const std::string& _filepath, std::vector<std::unique_ptr<Patient>>& _patients, std::vector<std::unique_ptr<Doctor>>& _doctors);
	static void SavePatients(const std::vector<std::unique_ptr<Person>>& _patients, const std::string& _filepath);
	static void SaveAllPersons(const std::vector<std::unique_ptr<Person>>& _persons, const std::string& _filepath);
};
