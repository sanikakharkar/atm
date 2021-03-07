#pragma once

class BankInterface
{
public:
    BankInterface() = default;
    ~BankInterface() = default;

    bool isCorrectPin(long long cardNumber, int pinNumber);

};