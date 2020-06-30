#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Currency
{
public:
    friend class Actor;
    
    // constructor
    Currency();
    Currency(int copper);

    // destructor
    ~Currency();

    // getters
    int GetGold(), GetSilver(), GetCopper();
    void DisplayMoney();

    // add or subtract
    void AddMoney(int copper);
    void SubtractMoney(int copper);

private:
    int copper{};

};