#pragma once

#include <iostream>
#include <vector>

class CardReader
{
public:
    CardReader() = default;
    ~CardReader() = default;

    bool readCardNumber(std::istream& stream);
    std::string getCardNumber();

protected:
    std::string cardNumber;

};


