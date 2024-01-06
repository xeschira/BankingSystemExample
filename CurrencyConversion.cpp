#include "CurrencyConversion.h"
#include <iostream>

void currencyConversion() {
    std::cout << "BTC-USD converter, enter 1 to convert from USD into BTC, enter 2 for from BTC into USD: ";
    int inp;
    std::cin >> inp;
    switch (inp) {
        case 1: {
            std::cout << "Enter amount of USD:";
            float usd;
            std::cin >> usd;
            float btc = usd / 38000;
            std::cout << "$" + std::to_string(usd) + " = " + std::to_string(btc) + " BTC.";
            break;
        }

        case 2: {
            std::cout << "Enter amount of BTC:";
            float btc;
            std::cin >> btc;
            float usd = btc * 38000;
            std::cout << std::to_string(btc) + " = $" + std::to_string(usd);
            break;
        }
        default: {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
        }
    }
}
