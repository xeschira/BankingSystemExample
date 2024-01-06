#include "WithdrawDeposit.h"
#include <iostream>
#include <algorithm>

void withdrawDeposit(std::vector<HesapBilgileri>& hesaplar, const std::string& tcKimlik) {
    auto it = std::find_if(hesaplar.begin(), hesaplar.end(), [&tcKimlik](const HesapBilgileri& hesap) {
        return hesap.tckimlik == tcKimlik;
    });

    if (it != hesaplar.end()) {
        std::cout << "Account Information:" << std::endl;
        std::cout << "Opening Date: " << it->acilisTarihi << std::endl;
        std::cout << "Branch: " << it->acanSube << std::endl;
        std::cout << "ID Number: " << it->tckimlik << std::endl;
        std::cout << "Account Number: " << it->hesapNumarasi << std::endl;
        std::cout << "Description: " << it->aciklama << std::endl;
        std::cout << "Currency: " << it->paraBirimi << std::endl;
        std::cout << "Balance: " << it->bakiye << std::endl;
        double amount;
        std::cout << "Enter the amount to withdraw (negative) or deposit (positive): ";
        std::cin >> amount;
        it->bakiye += amount;
        std::cout << "Updated Balance: " << it->bakiye << std::endl;
    } else {
        std::cout << "No account found for ID: " << tcKimlik << std::endl;
    }
}
