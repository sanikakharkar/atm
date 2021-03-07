#include <iostream>
#include "ATMCashBin.hpp"
#include "BankDatabase.hpp"
#include "BankInterface.hpp"
#include "CardReader.hpp"
#include "PINReader.hpp"

class ATM
{
public:
    ATM();
    ~ATM() = default;

    void run();

protected:
    ATMCashBin cashBin;
    BankInterface bankInterface;
    CardReader cardReader;
    PINReader pinReader;
};