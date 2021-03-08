#include "AccountData.hpp"
#include "BankDatabase.hpp"

class TestBankDatabase: public BankDatabase<std::string, AccountData>
{
public:
    void call_addDatabaseEntry(std::string key, AccountData data)
    {
        addDatabaseEntry(key, data);
    }
};
