#pragma once

#include <iostream>
#include "ATMCashBin.hpp"
#include "BankDatabase.hpp"
#include "BankInterface.hpp"
#include "CardReader.hpp"
#include "PINReader.hpp"

class ATM
{
public:
    ATM(BankDatabase<std::string, AccountData>& database, long long initialbalance);
    ~ATM() = default;

    void run(std::istream& inStream, std::ostream& outStream);

protected:
    bool acceptCard(std::istream& inStream, std::ostream& outStream);
    bool acceptPIN(std::istream& inStream, std::ostream& outStream);
    void performTransactions(std::istream& inStream, std::ostream& outStream);
    void performCheckBalance(std::istream& inStream, std::ostream& outStream);
    void performWithdraw(std::istream& inStream, std::ostream& outStream);
    void performDeposit(std::istream& inStream, std::ostream& outStream);
    void performEndSession(std::istream& inStream, std::ostream& outStream);

    ATMCashBin cashBin;
    BankInterface bankInterface;
    CardReader cardReader;
    PINReader pinReader;
};