#pragma once

#include "data_types.h"
#include <QString>

class ErrorHandling {
public:	
	static void ReportError(ErrorType _error, const QString& _context);
};
