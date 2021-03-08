#include "BankInterface.hpp"

BankInterface::BankInterface(BankDatabase<std::string, AccountData>& database)
:database{database}
{}

bool BankInterface::isValidCardNumber(std::string cardNumber)
{
    return database.isValidKey(cardNumber);
}

bool BankInterface::isCorrectPin(std::string cardNumber, std::string pinNumber)
{
    AccountData data = database.getAccountData(cardNumber);
    if (data.pinNumber != pinNumber)
    {
        return false;
    }
    this->cardNumber = cardNumber;
    return true;
}

long long BankInterface::checkBalance()
{
    return database.getAccountData(cardNumber).balance;
}

long long BankInterface::updateBalance(long long difference)
{
    database.getAccountData(cardNumber).balance += difference;
    return database.getAccountData(cardNumber).balance;
}
