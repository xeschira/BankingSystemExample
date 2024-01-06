// Validator.cpp

#include "Validator.h"
#include <algorithm>

bool checkExistence(const std::vector<std::string>& values, const std::string& value) {
    return std::find(values.begin(), values.end(), value) != values.end();
}
