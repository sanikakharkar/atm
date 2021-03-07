#include "ATM.hpp"

ATM::ATM()
:cashBin(ATMCashBin(0))
{}

void ATM::run()
{
    int maxInvalidAttempts = 5;
    int invalidAttempts = 0;
    bool endSession = false;

    std::cout << "Welcome!" << std::endl;
    std::cout << "Please enter your card number." << std::endl;

    while(!endSession)
    {
        if (!cardReader.readCardNumber(std::cin) || !bankInterface.isValidCardNumber(cardReader.getCardNumber()))
        {
            ++invalidAttempts;
            if (invalidAttempts < maxInvalidAttempts )
            {
                std::cout << "Please enter a valid 16-digit card number." << std::endl;
            }
            else
            {
                std::cout << "You have reached the maximum limit of invalid attempts. Ending current session" << std::endl;
                endSession = true;
                return;
            }
        }
        else
        {
            break;
        }
    }

    std::cout << "Please enter your PIN number." << std::endl;
    invalidAttempts = 0;
    while(!endSession)
    {
        if (!pinReader.readPinNumber(std::cin))
        {
            ++invalidAttempts;
            if (invalidAttempts < maxInvalidAttempts)
            {
                std::cout << "Please enter the correct 4-digit PIN." << std::endl;
            }
            else
            {
                std::cout << "You have reached the maximum limit of invalid attempts. Ending current session." << std::endl;
                endSession = true;
                return;
            }
        }
        else
        {
            break;
        }
    }

    std::cout << "Please enter an option number from the following: " << std::endl;
    std::cout << "1. Check balance" << std::endl;
    std::cout << "2. Withdraw amount" << std::endl;
    std::cout << "3. Deposit amount" << std::endl;
    std::cout << "4. End session" << std::endl;

    int option = 0;
    invalidAttempts = 0;
    while(!endSession)
    {
        std::cin >> option;
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
                std::cout << "Ending current session." << std::endl;
                return;
            }
            default:
            {
                ++invalidAttempts;
                if (invalidAttempts < maxInvalidAttempts)
                {
                    std::cout << "Please enter a valid option number." << std::endl;
                }
                else
                {
                    std::cout << "You have reached the maximum limit of invalid attempts. Ending current session." << std::endl;
                    endSession = true;
                }
                
            }
        }
    }
}