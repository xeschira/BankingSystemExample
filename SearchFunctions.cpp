#include "SearchFunctions.h"
#include <iostream>
#include <algorithm>

void searchForIdNumber(const std::vector<KisiselBilgiler>& kisiler,
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
