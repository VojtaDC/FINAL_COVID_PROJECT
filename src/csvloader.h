#pragma once

#include <vector>
#include <qsharedpointer.h>
#include <memory>
#include <functional>
#include <string>
#include "person.h"

// Forward declarations
class Doctor;
class Patient;

class CsvLoader {
public:
    
    // New type-based methods
    static std::vector<std::unique_ptr<Person>> loadAllPersons(const std::string& filepath);
    static std::vector<std::unique_ptr<Doctor>> filterDoctors(const std::vector<std::unique_ptr<Person>>& persons);
    static std::vector<std::unique_ptr<Patient>> filterPatients(const std::vector<std::unique_ptr<Person>>& persons);
    
private:
    static std::unique_ptr<Person> createPersonFromData(const std::vector<std::string>& data);
};
