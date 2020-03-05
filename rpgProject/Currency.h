#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
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
    int getGold(), getSilver(), getCopper();
    void displayMoney();

    // add or subtract
    void addMoney(int copper);
    void subtractMoney(int copper);

private:
    int copper{};

};