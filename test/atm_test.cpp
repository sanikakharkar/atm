#include <sstream>
#include "TestBankDatabase.hpp"
#include "ATM.hpp"

void test_InvalidCardNumber()
{
    std::cout << std::endl << "****TEST: INVALID CARD NUMBERS****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database, 0);
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
    std::cout << std::endl << "****TEST: VALID CARD NUMBER BUT INVALID PIN****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database, 0);
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

void test_ValidCardAndPIN_InvalidOption()
{
    std::cout << std::endl << "****TEST: VALID CARD AND PIN NUMBERS BUT INVALID OPTION****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database, 0);
    std::stringstream inStream;
    std::stringstream outStream;
    std::string number = "123456781234\n";
    std::string pinNumber = "1234\n";
    std::string option = "10\n";
    inStream << number << pinNumber << option;

    AccountData data;
    data.pinNumber = "1234";
    number = number.substr(0, number.size()-1);
    database.call_addDatabaseEntry(number, data);
    atm.run(inStream, outStream);
    std::cout << outStream.str() << std::endl;
    auto it = outStream.str().find("You have chosen option ");
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

void test_Option_CheckBalance()
{
    std::cout << std::endl << "****TEST: VALID TRANSACTION CHECK BALANCE****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database, 0);
    std::stringstream inStream;
    std::stringstream outStream;
    std::string number = "123456781234\n";
    std::string pinNumber = "1234\n";
    std::string option = "1\n";
    std::string optionEnd = "4\n";
    inStream << number << pinNumber << option << optionEnd;

    AccountData data;
    data.pinNumber = "1234";
    data.balance = 1000;
    number = number.substr(0, number.size()-1);
    database.call_addDatabaseEntry(number, data);
    atm.run(inStream, outStream);
    std::cout << outStream.str() << std::endl;
    auto it = outStream.str().find("Your current balance is: 1000$");
    if(it != std::string::npos)
    {
        std::cout << "****PASSED****" << std::endl;
    }
    else
    {
        std::cout << "****FALED****" << std::endl;
    }
    std::cout << std::endl;
}

void test_Option_WithdrawAmount()
{
    std::cout << std::endl << "****TEST: VALID TRANSACTION WITHDRAW****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database, 1000);
    std::stringstream inStream;
    std::stringstream outStream;
    std::string number = "123456781234\n";
    std::string pinNumber = "1234\n";
    std::string option = "2\n";
    std::string withdraw = "100\n";
    std::string optionEnd = "4\n";
    inStream << number << pinNumber << option << withdraw << optionEnd;

    AccountData data;
    data.pinNumber = "1234";
    data.balance = 1000;
    number = number.substr(0, number.size()-1);
    database.call_addDatabaseEntry(number, data);
    atm.run(inStream, outStream);
    std::cout << outStream.str() << std::endl;
    auto it = outStream.str().find("Your new balance is: 900$");
    if(it != std::string::npos)
    {
        std::cout << "****PASSED****" << std::endl;
    }
    else
    {
        std::cout << "****FALED****" << std::endl;
    }
    std::cout << std::endl;
}

void test_Option_DepositAmount()
{
    std::cout << std::endl << "****TEST: VALID TRANSACTION DEPOSIT****" << std::endl << std::endl;
    TestBankDatabase database;
    ATM atm(database, 1000);
    std::stringstream inStream;
    std::stringstream outStream;
    std::string number = "123456781234\n";
    std::string pinNumber = "1234\n";
    std::string option = "3\n";
    std::string deposit = "100\n";
    std::string optionEnd = "4\n";
    inStream << number << pinNumber << option << deposit << optionEnd;

    AccountData data;
    data.pinNumber = "1234";
    data.balance = 1000;
    number = number.substr(0, number.size()-1);
    database.call_addDatabaseEntry(number, data);
    atm.run(inStream, outStream);
    std::cout << outStream.str() << std::endl;
    auto it = outStream.str().find("Your new balance is: 1100$");
    if(it != std::string::npos)
    {
        std::cout << "****PASSED****" << std::endl;
    }
    else
    {
        std::cout << "****FALED****" << std::endl;
    }
    std::cout << std::endl;
}

int main()
{    
    test_InvalidCardNumber();
    test_ValidCardNumber_WrongPINNumber();
    test_ValidCardAndPIN_InvalidOption();
    test_Option_CheckBalance();
    test_Option_WithdrawAmount();
    test_Option_DepositAmount();

    return 0;
}

