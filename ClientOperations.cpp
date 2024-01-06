// ClientOperations.cpp

#include <iostream>
#include <vector>
#include "Validator.h"  // Include the Validator header
#include "MainStructs.h"  // Include the header containing your main structures
std::vector<std::string> getAllIDNumbers(const std::vector<KisiselBilgiler>& kisiler) {
    std::vector<std::string> idNumbers;
    for (const auto& kisi : kisiler) {
        idNumbers.push_back(kisi.tcKimlik);
    }
    return idNumbers;
}

std::string generateRandomIBAN() {
    std::string bban;
    for (int i = 0; i < 14; ++i) {
        bban += std::to_string(rand() % 10);
    }

    std::string country = "TR";
    std::string checkDigits = "00";
    std::string iban = country + checkDigits + bban;
    return iban;
}

void CreateNewClient(std::vector<KisiselBilgiler>& kisiler, std::vector<HesapBilgileri>& hesaplar) {
    KisiselBilgiler newClientPersonalInfo;
    HesapBilgileri newClientAccountInfo;

    std::cout << "Client's Name: ";
    std::cin >> newClientPersonalInfo.ad;
    std::cout << "Client's Surname: ";
    std::cin >> newClientPersonalInfo.soyad;
    std::cout << "Client's ID Number: ";
    std::cin >> newClientPersonalInfo.tcKimlik;

    // Check if the ID already exists
    if (checkExistence(getAllIDNumbers(kisiler), newClientPersonalInfo.tcKimlik)) {
        std::cout << "Error: ID Number already exists. Please enter a unique ID." << std::endl;
        return;
    }

    std::cout << "Account's Currency (TRY or USD): ";
    std::cin >> newClientAccountInfo.paraBirimi;
    std::cout << "Account's Statement: ";
    std::cin >> newClientAccountInfo.aciklama;
    std::cout << "Account's Branch: ";
    std::cin >> newClientAccountInfo.acanSube;
    std::cout << "Account's Date: ";
    std::cin >> newClientAccountInfo.acilisTarihi;

    newClientAccountInfo.bakiye = 0;
    newClientAccountInfo.hesapNumarasi = generateRandomIBAN();
    newClientAccountInfo.tckimlik = newClientPersonalInfo.tcKimlik;

    kisiler.push_back(newClientPersonalInfo);
    hesaplar.push_back(newClientAccountInfo);

    std::cout << "New client added successfully." << std::endl;
}
