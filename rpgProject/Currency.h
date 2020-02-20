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
    
    Currency();
    Currency(int gold, int silver, int copper);

    int getGold(), getSilver(), getCopper();
    void displayMoney();

    void addMoney(int gold, int silver, int copper);
    void subtractMoney(int gold, int silver, int copper);

private:
    int gold{};
    int silver{};
    int copper{};
};