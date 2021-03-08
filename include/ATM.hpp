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
    ATM(BankDatabase<std::string, AccountData>& database);
    ~ATM() = default;

    void run(std::istream& inStream, std::ostream& outStream);

protected:
    ATMCashBin cashBin;
    BankInterface bankInterface;
    CardReader cardReader;
    PINReader pinReader;
};