#include <string>
#include <regex>
#include "regex_validation.h"


bool RegexValidation::isValidated(ValType type, const std::string& string) {

	bool validated;
	std::regex regex_validation; //Contains regex expression for validation

	switch (type) {
	case(ValType::Password):
		/* (?=.*\\d) Checks if there's a number
		   (?=.*[a-z]) Checks if there's a small letter
		   (?=.*[A-Z]) Checks if there's a capital letter
		   (?=.*[-!@#$%^&*()_+=]) Checks if there's a special character
		   .{8,} Must be atleast 8 characters long */
		regex_validation = ("^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[-!@#$%^&*()_+=]).{8,}$");
		break;

	case(ValType::Phone):
		//^0 First number must be 0
		//\\d{8} Thereafter another 8  numbers (9 in total)
		regex_validation = ("^0\\d{8}$");
		break;

	case(ValType::GSM):
		//^0 First number must be zero
		//\\d{9} Thereafter another 9 numbers (10 in total)
		regex_validation = ("^0\\d{9}$");
		break;

	case(ValType::EMail):
		//^[\w-\\.]+ Checks to see if in the beginning there is at least one word character or a - or a . 
		//@ Thereafter must come a @
		//([\\w-]+\\.)+ After the @  must be atleast once one or more word characters or - followed by a .
		//[\\w-]{2,4} After the point should be another 2-4 word characters
		regex_validation = ("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
	}

	validated = std::regex_match(string, regex_validation); 
	return validated;
}