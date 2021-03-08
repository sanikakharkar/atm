#include <iostream>
#include "ATM.hpp"

int main()
{
    BankDatabase<std::string, AccountData> database;
    ATM atm(database, 0);
    atm.run(std::cin, std::cout);
    return 0;
}