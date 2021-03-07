#pragma once

#include <map>

template <class Key, class Data>
class BankDatabase
{
public:
    BankDatabase() = default;
    ~BankDatabase() = default;

protected:
    bool isValidKey(const Key key);

    Data& getAccountData(const Key key);

    void addDatabaseEntry(const Key key, const Data data);

    std::map<Key, Data> database;
};

template <class Key, class Data>
bool BankDatabase<Key, Data>::isValidKey(const Key key)
{
    auto it = database.find(key);
    if (it != database.end())
    {
        return true;
    }
    return false;
}

template <class Key, class Data>
Data& BankDatabase<Key, Data>::getAccountData(const Key key)
{
    return database[key];
}

template <class Key, class Data>
void BankDatabase<Key, Data>::addDatabaseEntry(const Key key, const Data data)
{
    database[key] = data;
}
