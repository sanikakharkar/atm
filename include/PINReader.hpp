#pragma once

class PINReader
{
public:
    PINReader() = default;
    ~PINReader() = default;
    
    void readPinNumber();
    int getPinNumber(); 

protected:
    int pinNumber;
};

