#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Sube {
public:
    std::string adres;
    std::string telefon;
    std::string branch_id;
};

class KisiselBilgiler {
public:
    std::string ad;
    std::string soyad;
    std::string tcKimlik;
};

class HesapBilgileri {
public:
    std::string acilisTarihi;
    std::string acanSube;
    std::string hesapNumarasi;
    std::string tckimlik;
    std::string aciklama;
    std::string paraBirimi;
    double bakiye;
};

class HesapHareketi {
public:
    std::string tcKimlik;
    double miktar;
    std::string tarih;
    std::string aciklama;

};

class Kredi {
public:
    std::string tcKimlik;
    double krediMiktari;
    double anaPara;
    double faizOrani;
};

class Fatura {
public:
    std::string tcKimlik;
    std::string musteri;
    std::string hesap;
    double miktar;
    std::string tarih;
    std::string sonOdemeTarihi;
};


void SearchByIdNumber(const std::vector<KisiselBilgiler>& kisiler,
                      const std::vector<HesapBilgileri>& hesaplar,
                      const std::vector<HesapHareketi>& hareketler,
                      const std::vector<Kredi>& krediler,
                      const std::vector<Fatura>& faturalar,
                      const std::string& tcKimlik) {
    bool found = false;

    for (const auto& kisi : kisiler) {
        if (kisi.tcKimlik == tcKimlik) {
            found = true;
            std::cout << "Personal Information:" << std::endl;
            std::cout << "Name: " << kisi.ad << std::endl;
            std::cout << "Surname: " << kisi.soyad << std::endl;
            std::cout << "ID Number:  " << kisi.tcKimlik << std::endl;
            break;
        }
    }

    if (!found) {
        std::cout << "No data found for ID Number:  " << tcKimlik << std::endl;
        return;
    }

    std::cout << "\nAccount Information:" << std::endl;
    for (const auto& hesap : hesaplar) {
        if (hesap.tckimlik == tcKimlik) {
            std::cout << "Opening Date: " << hesap.acilisTarihi << std::endl;
            std::cout << "Branch: " << hesap.acanSube << std::endl;
            std::cout << "Account Number: " << hesap.hesapNumarasi << std::endl;
            std::cout << "ID Number: " << hesap.tckimlik << std::endl;
            std::cout << "Description: " << hesap.aciklama << std::endl;
            std::cout << "Currency: " << hesap.paraBirimi << std::endl;
            std::cout << "Balance: " << hesap.bakiye << std::endl;
            break;
        }
    }

    std::cout << "\nAccount Movements:" << std::endl;
    for (const auto& hareket : hareketler) {
        if (hareket.tcKimlik == tcKimlik) {
            std::cout << "Amount: " << hareket.miktar << std::endl;
            std::cout << "Date: " << hareket.tarih << std::endl;
            std::cout << "Description: " << hareket.aciklama << std::endl;
        }
    }

    std::cout << "\nCredit Information:" << std::endl;
    for (const auto& kredi : krediler) {
        if (kredi.tcKimlik == tcKimlik) {
            std::cout << "Credit Amount: " << kredi.krediMiktari << std::endl;
            std::cout << "Principal: " << kredi.anaPara << std::endl;
            std::cout << "Interest Rate: " << kredi.faizOrani << std::endl;
            break;
        }
    }

    std::cout << "\nInvoice Information:" << std::endl;
    for (const auto& fatura : faturalar) {
        if (fatura.tcKimlik == tcKimlik) {
            std::cout << "Customer: " << fatura.musteri << std::endl;
            std::cout << "Amount: " << fatura.miktar << std::endl;
            std::cout << "Date: " << fatura.tarih << std::endl;
            std::cout << "Due Date: " << fatura.sonOdemeTarihi << std::endl;
            break;
        }
    }
}

void calculateCreditRisk(std::vector<Kredi>& krediler, const std::string& tcKimlik) {
    auto it = std::find_if(krediler.begin(), krediler.end(), [&tcKimlik](const Kredi& kredi) {
        return kredi.tcKimlik == tcKimlik;
    });

    if (it != krediler.end()) {
        std::cout << "You already have an unpaid loan. " << std::endl;
        std::cout << "ID Number: " << tcKimlik << std::endl;
        std::cout << "Credit Amount: " << it->krediMiktari << std::endl;
        std::cout << "Payback Amount: " << it->anaPara << std::endl;
        std::cout << "Interest Rate: " << it->faizOrani << std::endl;
    } else {
        int demandedCredit;
        int demandedPeriod;
        int monthlyIncome;
        std::cout << "Demanded amount:  " << std::endl;
        std::cin >> demandedCredit;
        std::cout << "Demanded maturity in month(s):  " << std::endl;
        std::cin >> demandedPeriod;
        std::cout << "Your monthly salary: " << std::endl;
        std::cin >> monthlyIncome;
        std::cout << "Interest Rate: " + std::to_string(2.91*demandedPeriod) << std::endl;
        int monthlypayment = (demandedCredit * ((2.91*demandedPeriod)/100))/demandedPeriod;
        std::cout << "Monthly Payment: " + std::to_string(monthlypayment) << std::endl;
        std::cout << "Total Payment: " + std::to_string(demandedCredit + (demandedCredit * ((2.91*demandedPeriod)/100))) << std::endl;
        if(monthlypayment < monthlyIncome){
            std::cout << "Your loan application has been accepted." << std::endl;
            krediler.push_back({tcKimlik, static_cast<double>(demandedCredit) , demandedCredit + (demandedCredit * ((2.91*demandedPeriod)/100)),2.91*demandedPeriod });
        }
        else {

            std::cout << "Your loan application rejected. Reason: HIGH RISK";

        }
    }
}

void listAllUsers(const std::vector<KisiselBilgiler>& kisiler) {
    std::cout << "List of All Users:" << std::endl;
    for (const auto& kisi : kisiler) {
        std::cout << "Name: " << kisi.ad << ", ";
        std::cout << "Surname: " << kisi.soyad << ", ";
        std::cout << "ID Number: " << kisi.tcKimlik << std::endl;
    }
}
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
void currencyConversion(){

    std::cout << "BTC-USD converter, enter 1 to convert from USD into BTC, enter 2 for from BTC into USD: ";
    int inp;
    std::cin >> inp;
    switch (inp) {
        case 1:{
            std::cout << "Enter amount of USD:";
            float usd;
            std::cin >> usd;
            float btc = usd/38000;
            std::cout << "$" + std::to_string(usd) + " = " + std::to_string(btc) + " BTC.";
            break;
        }

        case 2:{
            std::cout << "Enter amount of BTC:";
            float btc;
            std::cin >> btc;
            float usd = btc*38000;
            std::cout << std::to_string(btc) + " = $" + std::to_string(usd);
            break;
        }
        default: {
            std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
        }
    }

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
}
int main() {
    std::vector<KisiselBilgiler> kisiler = {
            {"Steve", "Jobs", "1234567890"},
            {"Linus", "Torvalds", "9876543210"}
    };

    std::vector<HesapBilgileri> hesaplar = {
            {"2023-01-01", "Kaliforniya Merkez Şube", generateRandomIBAN(),"1234567890", "Pankreas kanseri tedavi parasi", "USD", 805000000.0},
            {"2023-02-01", "Dijital Sube", generateRandomIBAN(),"9876543210", "r/linux bagis hesabi", "BTC", 435.65}
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
                SearchByIdNumber(kisiler, hesaplar, hareketler, krediler, faturalar, ID_number);
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
                CreateNewClient(kisiler, hesaplar);
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