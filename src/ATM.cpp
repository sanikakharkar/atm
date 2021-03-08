#include "ATM.hpp"

ATM::ATM(BankDatabase<std::string, AccountData>& database)
:cashBin(ATMCashBin(0)),
bankInterface(BankInterface(database))
{}

void ATM::run(std::istream& inStream, std::ostream& outStream)
{
    int maxInvalidAttempts = 5;
    int invalidAttempts = 0;
    bool endSession = false;

    outStream << "Welcome!" << std::endl;
    outStream << "Please enter your card number." << std::endl;

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
                return;
            }
        }
        else
        {
            outStream << "Your have selected account " << cardReader.getCardNumber() << std::endl;
            break;
        }
    }

    outStream << "Please enter your PIN number." << std::endl;
    invalidAttempts = 0;
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
                return;
            }
        }
        else
        {
            break;
        }
    }

    outStream << "Please enter an option number from the following: " << std::endl;
    outStream << "1. Check balance" << std::endl;
    outStream << "2. Withdraw amount" << std::endl;
    outStream << "3. Deposit amount" << std::endl;
    outStream << "4. End session" << std::endl;

    int option = 0;
    invalidAttempts = 0;
    while(!endSession)
    {
        inStream >> option;
        switch(option)
        {
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                endSession = true;
                outStream << "Ending current session." << std::endl;
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
                }
                
            }
        }
    }
}