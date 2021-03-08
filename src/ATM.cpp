#include "ATM.hpp"

ATM::ATM(BankDatabase<std::string, AccountData>& database, long long initialbalance)
:cashBin(ATMCashBin(initialbalance)),
bankInterface(BankInterface(database))
{}

void ATM::run(std::istream& inStream, std::ostream& outStream)
{
    outStream << "Welcome!" << std::endl;

    if (!acceptCard(inStream, outStream))
    {
        return;
    }
    if (!acceptPIN(inStream, outStream))
    {
        return;
    }
    performTransactions(inStream, outStream);
    return;
}

bool ATM::acceptCard(std::istream& inStream, std::ostream& outStream)
{
    outStream << "Please enter your card number." << std::endl << std::endl;
    int maxInvalidAttempts = 5;
    int invalidAttempts = 0;
    bool endSession = false;
    while(!endSession)
    {
        if (!cardReader.readCardNumber(inStream) || !bankInterface.isValidCardNumber(cardReader.getCardNumber()))
        {
            ++invalidAttempts;
            if (invalidAttempts < maxInvalidAttempts )
            {
                outStream << cardReader.getCardNumber() << " is invalid. Please enter a valid 12-digit card number." << std::endl;
            }
            else
            {
                outStream << cardReader.getCardNumber() << " is invalid. You have reached the maximum limit of invalid attempts. Ending current session" << std::endl;
                endSession = true;
                return false;;
            }
        }
        else
        {
            outStream << "You have selected account " << cardReader.getCardNumber() <<  std::endl << std::endl;
            return true;
        }
    }
    return false;
}

bool ATM::acceptPIN(std::istream& inStream, std::ostream& outStream)
{
    outStream << "Please enter your PIN number." << std::endl << std::endl;
    int maxInvalidAttempts = 5;
    int invalidAttempts = 0;
    bool endSession = false;
    while(!endSession)
    {
        if (!pinReader.readPinNumber(inStream) || !bankInterface.isCorrectPin(cardReader.getCardNumber(), pinReader.getPinNumber()))
        {
            ++invalidAttempts;
            if (invalidAttempts < maxInvalidAttempts)
            {
                outStream << "Please enter the correct 4-digit PIN." << std::endl;
            }
            else
            {
                outStream << "You have reached the maximum limit of invalid attempts. Ending current session." << std::endl;
                endSession = true;
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

void ATM::performTransactions(std::istream& inStream, std::ostream& outStream)
{
    outStream << "Please enter an option number from the following: " << std::endl;
    outStream << "1. Check balance" << std::endl;
    outStream << "2. Withdraw amount" << std::endl;
    outStream << "3. Deposit amount" << std::endl;
    outStream << "4. End session" << std::endl << std::endl;

    int option = 0;
    int maxInvalidAttempts = 5;
    int invalidAttempts = 0;
    bool endSession = false;
    while(!endSession)
    {
        inStream >> option;
        switch(option)
        {
            case 1:
            {
                performCheckBalance(inStream, outStream);
                break;
            }
            case 2:
            {
                performWithdraw(inStream, outStream);
                break;
            }
            case 3:
            {
                performDeposit(inStream, outStream);
                break;
            }
            case 4:
            {
                performEndSession(inStream, outStream);
                return;
            }
            default:
            {
                ++invalidAttempts;
                if (invalidAttempts < maxInvalidAttempts)
                {
                    outStream << "Please enter a valid option number." << std::endl;
                }
                else
                {
                    outStream << "You have reached the maximum limit of invalid attempts. Ending current session." << std::endl;
                    endSession = true;
                    return;
                }
                
            }
        }
    }
    return;
}

void ATM::performCheckBalance(std::istream& inStream, std::ostream& outStream)
{
    outStream << "You have chosen option 1: Check balance" << std::endl;
    outStream << "Your current balance is: " << bankInterface.checkBalance() << "$" << std::endl << std::endl;
}

void ATM::performWithdraw(std::istream& inStream, std::ostream& outStream)
{
    outStream << "You have chosen option 2: Withdraw amount" << std::endl;
    outStream << "Please enter the amount you'd like to withdraw." << std::endl;
    long long withdraw;
    inStream >> withdraw;
    if (cashBin.withdraw(withdraw))
    {
        if (withdraw > bankInterface.checkBalance())
        {
            outStream << "Your current balance is: " << bankInterface.checkBalance() << "$. Please enter a lesser amount." << std::endl;
        }
        else
        {
            outStream << "You have withdrawn " << withdraw << "$. Please collect your amount from the tray." << std::endl;
            outStream << "Your new balance is: " << bankInterface.updateBalance(-withdraw) << "$" << std::endl;
        }
    }
    else
    {
        outStream << "Amount exceeds the maximum amount in the ATM. Please enter a lesser amount." << std::endl;
    }
    outStream << std::endl;
}

void ATM::performDeposit(std::istream& inStream, std::ostream& outStream)
{
    outStream << "You have chosen option 3: Deposit amount" << std::endl;
    outStream << "Please enter the amount you'd like to deposit and place it in the tray." << std::endl;
    long long deposit;
    inStream >> deposit;
    cashBin.deposit(deposit);
    outStream << "You have deposited " << deposit << "$." << std::endl;
    outStream << "Your new balance is: " << bankInterface.updateBalance(deposit) << "$" << std::endl << std::endl;
}

void ATM::performEndSession(std::istream& inStream, std::ostream& outStream)
{
    outStream << "You have chosen option 4: End session" << std::endl;
    outStream << "Ending current session." << std::endl;
}