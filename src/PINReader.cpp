#include "PINReader.hpp"

bool PINReader::readPinNumber(std::istream& stream)
{
    stream >> pinNumber;
    if (pinNumber.size() != 4)
    {
        return false;
    }
    return true;
}

std::string PINReader::getPinNumber()
{
    return pinNumber;
}