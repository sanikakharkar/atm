#include <iostream>
#include "ATMCashBin.hpp"
#include "BankDatabase.hpp"
#include "BankInterface.hpp"
#include "CardReader.hpp"
#include "PINReader.hpp"

int main()
{
    ATMCashBin cashBin(0);
    BankInterface bankInterface;
    CardReader cardReader;
    PINReader pinReader;
    std::cout << "Please insert your card." << std::endl;
    return 0;
}