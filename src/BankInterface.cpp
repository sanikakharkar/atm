#include "BankInterface.hpp"

bool BankInterface::isValidCardNumber(std::string cardNumber)
{
    return isValidKey(cardNumber);
}

bool BankInterface::isCorrectPin(std::string cardNumber, std::string pinNumber)
{
    AccountData data = getAccountData(cardNumber);
    if (data.pinNumber != pinNumber)
    {
        return false;
    }
    this->cardNumber = cardNumber;
    return true;
}

long long BankInterface::checkBalance()
{
    return getAccountData(cardNumber).balance;
}

long long BankInterface::updateBalance(long long difference)
{
    getAccountData(cardNumber).balance += difference;
    return getAccountData(cardNumber).balance;
}
