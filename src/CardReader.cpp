#include "CardReader.hpp"

bool CardReader::readCardNumber(std::istream& stream)
{
    stream >> cardNumber;
    if (cardNumber.size() != 12)
    {
        return false;
    }
    return true;
}

std::string CardReader::getCardNumber()
{
    return cardNumber;
}