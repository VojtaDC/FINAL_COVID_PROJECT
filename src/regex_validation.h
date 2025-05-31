#pragma once
#include "data_types.h"
#include <QString>

class RegexValidation {
public:
	static bool IsValidated(ValType _type, const QString& _string);
};
