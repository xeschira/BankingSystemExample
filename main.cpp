#include <iostream>
#include <vector>
#include <string>

#include "MainStructs.h"
#include "ClientOperations.h"
#include "CreditOperations.h"
#include "SearchFunctions.h"
#include "CurrencyConversion.h"
#include "withdrawDeposit.h"


void listAllUsers(const std::vector<KisiselBilgiler>& kisiler) {
    std::cout << "List of All Users:" << std::endl;
    for (const auto& kisi : kisiler) {
        std::cout << "Name: " << kisi.ad << ", ";
        std::cout << "Surname: " << kisi.soyad << ", ";
        std::cout << "ID Number: " << kisi.tcKimlik << std::endl;
    }
}


int main() {
    std::vector<Sube> subeler = {
            {"Kaliforniya Merkez Sube","Merkez Mah. JFK Sokak No:1/A", "+1 009 345 66 78", "001"},
            {"Dijital Sube","http://www.cokguvenlibibanka.xyz", "+1 435 543 12 47", "002"}
    };

    std::vector<KisiselBilgiler> kisiler = {
            {"Steve", "Jobs", "1234567890"},
            {"Linus", "Torvalds", "9876543210"}
    };

    std::vector<HesapBilgileri> hesaplar = {
            {"2023-01-01", "Kaliforniya Merkez Şube", "TR660006224847992593916619","1234567890", "Pankreas kanseri tedavi parasi", "USD", 805000000.0},
            {"2023-02-01", "Dijital Sube", "TR240006227944516178211794","9876543210", "r/linux bagis hesabi", "BTC", 435.65}
    };

    std::vector<HesapHareketi> hareketler = {
            {"1234567890", 432565.0, "2023-01-02", "Hisse Satisi $AAPL"},
            {"9876543210", -45.0, "2023-02-02", "NVIDIA Para cezası tahsilat"}
    };

    std::vector<Kredi> krediler = {
            {"1234567890", 5000.0, 4500.0, 0.05},
    };

    std::vector<Fatura> faturalar = {
            {"1234567890", "Steve Jobs", "1234567890", 50.0, "2011-04-03", "2012-04-03"},
            {"9876543210", "Linus Torvalds", "9876543210", 30.0, "2023-02-03", "2024-02-13"}
    };

    int choice;
    do {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Withdraw/Deposit money by ID Number" << std::endl;
        std::cout << "2. Search user via ID Number" << std::endl;
        std::cout << "3. List all users" << std::endl;
        std::cout << "4. Credits" << std::endl;
        std::cout << "5. Add New Client" << std::endl;
        std::cout << "6. Convert currency" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice (1-7): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string ID_number;
                std::cout << "Enter ID Number: ";
                std::cin >> ID_number;
                withdrawDeposit(hesaplar, ID_number);
                break;
            }
            case 2: {
                std::string ID_number;
                std::cout << "Enter ID Number: ";
                std::cin >> ID_number;
                searchForIdNumber(kisiler, hesaplar, hareketler, krediler, faturalar, ID_number);
                break;
            }
            case 3: {
                listAllUsers(kisiler);
                break;
            }
            case 4: {
                std::string ID_number;
                std::cout << "Enter ID Number: ";
                std::cin >> ID_number;
                calculateCreditRisk(krediler, ID_number);
                break;
            }
            case 5: {
                CreateNewClient(kisiler, hesaplar, subeler);
                break;
            }
            case 6: {
                currencyConversion();
                break;
            }
            case 7: {
                std::cout << "Exiting the program." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 7." << std::endl;
        }
    } while (choice != 7);

    return 0;
}