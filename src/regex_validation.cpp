#include <string>
#include "regex_validation.h"
#include <QDebug>
#include <QRegExp>
#include <QString>

bool RegexValidation::IsValidated(ValType _type, const std::string& _string) {

    bool validated = false; // Initialiseer validated
    QRegExp current_regex; // Gebruik QRegExp in plaats van std::regex
    QString qstr = QString::fromStdString(_string); // Convert std::string naar QString

    switch (_type) {
    case(ValType::Password):
        /* (?=.*\\d) Checks if there's a number
           (?=.*[a-z]) Checks if there's a small letter
           (?=.*[A-Z]) Checks if there's a capital letter
           (?=.*[-!@#$%^&*()_+=]) Checks if there's a special character
           .{8,} Must be atleast 8 characters long */
        // QRegExp ondersteunt geen lookahead, dus we moeten het patroon aanpassen
        current_regex.setPattern("^(?=.*\\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[-!@#$%^&*()_+=]).{8,}$");
        current_regex.setPatternSyntax(QRegExp::RegExp2); // Gebruik RegExp2 voor betere ondersteuning
        break;

    case(ValType::Phone):
        //^0 First number must be 0
        //\\d{8} Thereafter another 8  numbers (9 in total)
        current_regex.setPattern("^0\\d{8}$");
        current_regex.setPatternSyntax(QRegExp::RegExp2);
        break;

    case(ValType::GSM):
        //^0 First number must be zero
        //\\d{9} Thereafter another 9 numbers (10 in total)
        current_regex.setPattern("^0\\d{9}$");
        current_regex.setPatternSyntax(QRegExp::RegExp2);
        break;

    case(ValType::EMail):
        //^[\w-\.]+ Checks to see if in the beginning there is at least one word character or a - or a . 
        //@ Thereafter must come a @
        //([\w-]+\.)+ After the @  must be atleast once one or more word characters or - followed by a .
        //[\w-]{2,4} After the point should be another 2-4 word characters
        current_regex.setPattern("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
        current_regex.setPatternSyntax(QRegExp::RegExp2);
        break;
    default:
        return false; // Ongeldig type, retourneer false
    }
    
    // QRegExp throws no exceptions, so we check for invalid patterns
    if (!current_regex.isValid()) {
        // Pattern is invalid, return false
        return false;
    }
    
    validated = current_regex.exactMatch(qstr);
    return validated;
}