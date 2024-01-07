// ClientOperations.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>
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
std::string getCurrentWorkingDirectory() {
    char buffer[FILENAME_MAX];
#ifdef _WIN32
    _getcwd(buffer, FILENAME_MAX);
#else
    getcwd(buffer, FILENAME_MAX);
#endif
    return std::string(buffer);
}

void CreateNewClient(std::vector<KisiselBilgiler>& kisiler, std::vector<HesapBilgileri>& hesaplar,std::vector<Sube>& sube) {
    KisiselBilgiler newClientPersonalInfo;
    HesapBilgileri newClientAccountInfo;

    std::cout << "Client's Name: ";
    std::cin >> newClientPersonalInfo.ad;
    if (containsNumbers(newClientPersonalInfo.ad)) {
        std::cout << "Error: Name should not contain numbers. Please enter a valid name." << std::endl;
        return;
    }
    std::cout << "Client's Surname: ";
    std::cin >> newClientPersonalInfo.soyad;
    if (containsNumbers(newClientPersonalInfo.soyad)) {
        std::cout << "Error: Surname should not contain numbers. Please enter a valid Surname." << std::endl;
        return;
    }
    std::cout << "Client's ID Number: ";
    std::cin >> newClientPersonalInfo.tcKimlik;

    // Check if the ID format is valid
    if (!isValidTurkishID(newClientPersonalInfo.tcKimlik)) {
        std::cout << "Error: Invalid ID Number format. Please enter a valid Turkish ID." << std::endl;
        return;
    }

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
    // Display available branches
    std::cout << "Available Branches:\n";
    for (size_t i = 0; i < sube.size(); ++i) {
        std::cout << i + 1 << ". " << sube[i].isim << "\n";
    }

    std::cout << "Choose Account's Branch (enter the corresponding number): ";
    int branchChoice;
    std::cin >> branchChoice;

    // Check if the choice is valid
    if (branchChoice < 1 || branchChoice > sube.size()) {
        std::cout << "Error: Invalid branch choice. Please enter a valid number." << std::endl;
        return;
    }

    newClientAccountInfo.acanSube = sube[branchChoice - 1].isim;
    std::cout << "Account's Date: ";
    std::cin >> newClientAccountInfo.acilisTarihi;

    newClientAccountInfo.bakiye = 0;
    newClientAccountInfo.hesapNumarasi = generateRandomIBAN();
    newClientAccountInfo.tckimlik = newClientPersonalInfo.tcKimlik;

    kisiler.push_back(newClientPersonalInfo);
    hesaplar.push_back(newClientAccountInfo);
    std::string signature = newClientPersonalInfo.ad + newClientPersonalInfo.soyad + newClientPersonalInfo.tcKimlik;

    // Create the file path in the main directory under the "signatures" folder
    std::string filePath = getCurrentWorkingDirectory() + "\\signatures\\" + newClientPersonalInfo.tcKimlik + ".txt";
    newClientPersonalInfo.signature = filePath;
    std::cout << newClientPersonalInfo.signature;
    // Write the signature to the file
    std::ofstream signatureFile(filePath);
    if (signatureFile.is_open()) {
        signatureFile << signature;
        signatureFile.close();
        std::cout << "Signature file created successfully." << std::endl;
    } else {
        std::cout << "Error: Unable to create signature file." << std::endl;
    }
    std::cout << "New client added successfully." << std::endl;
}
