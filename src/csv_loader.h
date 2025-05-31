#pragma once

#include <vector>
#include <qsharedpointer.h>
#include <memory>
#include <functional>
#include <string>
#include "person.h"
#include "data_types.h"
#include "patient.h"
#include "doctor.h"


// Forward declarations

class CsvLoader {
public:

	// New type-based methods
	static void LoadAllPersons(const std::string& _filepath, std::vector<std::unique_ptr<Patient>>& _patients, std::vector<std::unique_ptr<Doctor>>& _doctors, ErrorType& _error);
	static void SaveAllPersons(const std::vector<std::unique_ptr<Patient>>& _patients, const std::vector<std::unique_ptr<Doctor>>& _doctors, const std::string& _filepath, ErrorType& _error);
};
