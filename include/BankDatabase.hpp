#pragma once

#include <map>

template <class Key, class Data>
class BankDatabase
{
public:
    virtual ~BankDatabase() = 0;

protected:
    virtual Data getAccountData(Key key) = 0;

    std::map<Key, Data> database;
};