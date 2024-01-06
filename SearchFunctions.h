#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H

#include <vector>
#include "MainStructs.h"

void searchForIdNumber(const std::vector<KisiselBilgiler>& kisiler,
                       const std::vector<HesapBilgileri>& hesaplar,
                       const std::vector<HesapHareketi>& hareketler,
                       const std::vector<Kredi>& krediler,
                       const std::vector<Fatura>& faturalar,
                       const std::string& tcKimlik);

#endif // SEARCH_FUNCTIONS_H
