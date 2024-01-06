// MainStructs.h

#ifndef MAIN_STRUCTS_H
#define MAIN_STRUCTS_H

#include <string>

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

#endif // MAIN_STRUCTS_H
