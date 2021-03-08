#pragma once

class ATMCashBin
{
public:
    ATMCashBin(long long initialBalance);

    bool withdraw(long long amount);
    void deposit(long long amount);
    
protected:
    long long balance;

};