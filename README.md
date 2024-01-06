### This is a midterm assignment for class IST2003 at Karadeniz Technical University. 
# ---
# Banking Management System

## Overview

This C++ project represents a Banking Management System simulation. It consists of several header and source files, each serving a specific purpose within the program.

## Project Structure

### Header Files

1. **MainStructs.h**: Defines main data structures used in the program, such as `Sube`, `KisiselBilgiler`, `HesapBilgileri`, `HesapHareketi`, `Kredi`, and `Fatura`.

2. **Validator.h**: Includes the `checkExistence` function for input validation, ensuring the existence of a value in a vector.

3. **ClientOperations.h**: Contains functions related to user operations, including `CreateNewClient`, `calculateCreditRisk`, `listAllUsers`, and `withdrawDeposit`.

4. **CurrencyConversion.h**: Includes the `currencyConversion` function for currency conversion operations.

5. **SearchForIdNumber.h**: Holds the `SearchForIdNumber` function for searching a user with a specific ID Number.

### Source Files

1. **Main.cpp**: The main application file managing program initiation and user interface. It provides a menu-driven interface for users to perform various banking operations.

2. **MainStructs.cpp**: Defines the main data structures.

3. **Validator.cpp**: Implements validation operations.

4. **ClientOperations.cpp**: Implements user-related operations, including `createNewClient`, `calculateCreditRisk`, `listAllUsers`, and `withdrawDeposit`.

5. **CurrencyConversion.cpp**: Implements currency conversion operations.

6. **SearchForIdNumber.cpp**: Implements the user search functionality based on a specific ID Number.

## Usage

1. Compile and run the program by compiling the `Main.cpp` file.

2. Choose the desired operation from the menu to perform various banking tasks.

---

Feel free to customize and expand this README.md according to your needs!
