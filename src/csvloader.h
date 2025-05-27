#pragma once

#include <vector>
#include <qsharedpointer.h>
#include <memory>
#include <functional>
#include <string>
#include "person.h"

class CsvLoader {
public:
    // Legacy method - can be kept for backwards compatibility
    static std::vector<std::unique_ptr<Person>> loadPersons(const std::string& filepath, const std::string& doctor_or_patient);
    
    // New template-based method
    template<typename T>
    static std::vector<std::unique_ptr<T>> load(
        const std::string &filepath,
        std::function<std::unique_ptr<T>(const std::vector<std::string>&)> factory);
        
};
