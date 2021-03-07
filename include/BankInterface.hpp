#pragma once

#include "BankDatabase.hpp"

struct AccountData
{
    std::string cardNumber;
    std::string pinNumber;
    long long balance;
};

class BankInterface : public BankDatabase<std::string, AccountData>
{
public:
    BankInterface() = default;
    ~BankInterface() = default;

    bool isValidCardNumber(std::string cardNumber);

    bool isCorrectPin(std::string cardNumber, std::string pinNumber);

    long long checkBalance();

    long long updateBalance(long long difference);
   
protected:
    std::string cardNumber;

};
