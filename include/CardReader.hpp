#pragma once

class CardReader
{
public:
    CardReader() = default;
    ~CardReader() = default;

    void readCardNumber();
    long long getCardNumber();

protected:
    long long cardNumber;
};


