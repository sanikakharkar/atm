#include <sstream>
#include "TestBankDatabase.hpp"
#include "ATM.hpp"

void test_InvalidCardNumber()
{
    std::cout << std::endl << "****TEST INVALID CARD NUMBERS****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database);
    std::stringstream inStream;
    std::stringstream outStream;
    inStream << "1\n";
    inStream << "11\n";
    inStream << "11111111111111111\n";
    inStream << "11111\n";
    inStream << "111111111111\n"; // 12-digit number but does not exist in database
    atm.run(inStream, outStream);
    std::cout << outStream.str() << std::endl;
    auto it = outStream.str().find("Please enter your PIN number.");
    if(it == std::string::npos)
    {
        std::cout << "****PASSED****" << std::endl;
    }
    else
    {
        std::cout << "****FALED****" << std::endl;
    }
    std::cout << std::endl;
}

void test_ValidCardNumber_WrongPINNumber()
{
    std::cout << std::endl << "****TEST VALID CARD NUMBER BUT INVALID PIN****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database);
    std::stringstream inStream;
    std::stringstream outStream;
    std::string number = "123456781234\n";
    std::string pinNumber = "1233\n";
    inStream << number << pinNumber;

    AccountData data;
    data.pinNumber = "1234";
    number = number.substr(0, number.size()-1);
    database.call_addDatabaseEntry(number, data);
    atm.run(inStream, outStream);
    std::cout << outStream.str() << std::endl;
    auto it = outStream.str().find("Please enter an option number from the following: ");
    if(it == std::string::npos)
    {
        std::cout << "****PASSED****" << std::endl;
    }
    else
    {
        std::cout << "****FALED****" << std::endl;
    }
    std::cout << std::endl;
}

void testOptionCheckBalance()
{

}

void testOptionWithdrawAmount()
{
    
}

void testOptionDepositAmount()
{
    
}

void testOptionEndSession()
{
    
}

int main()
{    
    test_InvalidCardNumber();
    test_ValidCardNumber_WrongPINNumber();
    testOptionCheckBalance();
    testOptionWithdrawAmount();
    testOptionDepositAmount();
    testOptionEndSession();

    return 0;
}

