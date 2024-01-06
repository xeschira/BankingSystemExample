### This is a midterm assignment for class IST2003 at Karadeniz Technical University. 
# ---
# Banking Management System

## Overview

This C++ project is a Banking Management System simulation, offering various functionalities related to user accounts, transactions, and financial operations.

## Project Structure

### Default Data

The program initializes with default data representing clients, accounts, transactions, loans, and invoices. This data serves as a sample for testing and demonstrating the program's capabilities.

### Functions

#### 1. **CreateNewClient**
- Functionality: Allows the addition of a new client to the system with personalized details.
- Usage: Select option 5 from the menu, provide the required information, and a new client will be added.

#### 2. **WithdrawDeposit**
- Functionality: Enables users to withdraw or deposit money into their accounts.
- Usage: Select option 1, enter the ID Number, and specify the amount to withdraw (negative) or deposit (positive).

#### 3. **SearchForIdNumber**
- Functionality: Searches for a user based on their ID Number and displays their personal and financial information.
- Usage: Select option 2, enter the ID Number, and the program will display the relevant details.

#### 4. **ListAllUsers**
- Functionality: Lists all users with their names, surnames, and ID Numbers.
- Usage: Select option 3, and the program will display a list of all registered users.

#### 5. **CalculateCreditRisk**
- Functionality: Assesses the credit risk for a user based on their existing loans and financial information.
- Usage: Select option 4, enter the ID Number, and the program will provide credit risk details.

#### 6. **CurrencyConversion**
- Functionality: Converts currency between USD and BTC.
- Usage: Select option 6, choose the conversion type, and input the amount to perform the conversion.

#### 7. **Exit**
- Functionality: Terminates the program.
- Usage: Select option 7 to exit the program.

### Menu Operation

The program operates through a user-friendly menu interface, where users can choose from various options (1-7). Each option corresponds to a specific function, allowing users to interact with the banking system efficiently.

## Usage

1. Compile and run the program by compiling the `Main.cpp` file.
2. Follow the on-screen menu prompts to perform banking operations.

---

Feel free to explore and test the program using the default data and functionalities provided!
