// CreditOperations.cpp

#include "CreditOperations.h"


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
