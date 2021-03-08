#pragma once

#include <iostream>
#include "AccountData.hpp"
#include "BankDatabase.hpp"

class BankInterface
{
public:
    BankInterface(BankDatabase<std::string, AccountData>& database);
    ~BankInterface() = default;

    bool isValidCardNumber(std::string cardNumber);

    bool isCorrectPin(std::string cardNumber, std::string pinNumber);

    long long checkBalance();

    long long updateBalance(long long difference);
   
protected:
    std::string cardNumber;
    BankDatabase<std::string, AccountData>& database;
};
