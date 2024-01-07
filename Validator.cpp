// Validator.cpp

#include "Validator.h"
#include <algorithm>
#include <cctype>

bool checkExistence(const std::vector<std::string>& values, const std::string& value) {
    return std::find(values.begin(), values.end(), value) != values.end();
}

bool isValidTurkishID(const std::string& idNumber) {
    // Check if the ID has 11 digits
    if (idNumber.length() != 11) {
        return false;
    }

    // Check if the first digit is not zero
    if (idNumber[0] == '0') {
        return false;
    }

    // Calculate the check digits
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 0; i < 9; i += 2) {
        oddSum += idNumber[i] - '0';
    }

    for (int i = 1; i < 10; i += 2) {
        evenSum += idNumber[i] - '0';
    }

    int totalSum = (oddSum * 7 - evenSum) % 10;

    // Check if the calculated check digits match the last two digits of the ID
    return (totalSum == idNumber[9] - '0') && ((oddSum + evenSum + totalSum) % 10 == idNumber[10] - '0');
}
bool containsNumbers(const std::string& str) {
    for (char ch : str) {
        if (std::isdigit(ch)) {
            return true;  // Name contains at least one digit
        }
    }
    return false;  // Name does not contain any digits
}