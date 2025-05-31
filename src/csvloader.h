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
    static std::vector<std::unique_ptr<Person>> LoadAllPersons(const std::string& _filepath);
    static std::vector<std::unique_ptr<Doctor>> FilterDoctors(const std::vector<std::unique_ptr<Person>>& _persons);
    static std::vector<std::unique_ptr<Patient>> FilterPatients(const std::vector<std::unique_ptr<Person>>& _persons);
    static void SavePatients(const std::vector<std::unique_ptr<Person>>& _patients, const std::string& _filepath);
    static void SaveAllPersons(const std::vector<std::unique_ptr<Person>>& _persons, const std::string& _filepath);

private:
    static std::unique_ptr<Person> CreatePersonFromData(const std::vector<std::string>& _data);
};
