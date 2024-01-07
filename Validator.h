// Validator.h
#include <string>
#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>
#include <string>

bool checkExistence(const std::vector<std::string>& values, const std::string& value);
bool isValidTurkishID(const std::string& idNumber);
bool containsNumbers(const std::string& str);
#endif // VALIDATOR_H
