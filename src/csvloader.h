#pragma once

#include <vector>
#include <qsharedpointer.h>
#include "person.h"

class CsvLoader {
public:
	static std::vector<std::unique_ptr<Person>> loadPersons(const std::string& filepath, const std::string& doctor_or_patient);
};
