cmake_minimum_required(VERSION 3.27)
project(BankingSystemExample)

set(CMAKE_CXX_STANDARD 17)

add_executable(BankingSystemExample main.cpp
        Validator.cpp
        Validator.h
        ClientOperations.cpp
        ClientOperations.h
        MainStructs.h
        CreditOperations.cpp
        CreditOperations.h
        SearchFunctions.cpp
        SearchFunctions.h
        CurrencyConversion.cpp
        CurrencyConversion.h
        withdrawDeposit.cpp
        withdrawDeposit.h
)
