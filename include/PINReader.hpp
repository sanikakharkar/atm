#pragma once

#include <iostream>

class PINReader
{
public:
    PINReader() = default;
    ~PINReader() = default;
    
    bool readPinNumber(std::istream& stream);
    std::string getPinNumber(); 

protected:
    std::string pinNumber;
};

