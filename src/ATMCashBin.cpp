#include "ATMCashBin.hpp"

ATMCashBin::ATMCashBin(long long initialBalance)
:balance{initialBalance}
{};

bool ATMCashBin::withdraw(long long amount)
{
    if (amount < balance)
    {
        balance -= amount;
        return true;
    }
    return false;
}

void ATMCashBin::deposit(long long amount)
{
    balance += amount;
}