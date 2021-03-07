#pragma once

class ATMCashBin
{
public:
    ATMCashBin(unsigned long long initialBalance)
    :balance{initialBalance}
    {};

    bool withdraw(unsigned long long amount);
    void deposit(unsigned long long amount);

protected:
    unsigned long long balance;

};