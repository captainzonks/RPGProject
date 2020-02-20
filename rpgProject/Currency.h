#pragma once

#include <iostream>

class Currency
{
public:
    
    Currency();
    Currency(int gold, int silver, int copper);

    int getGold(), getSilver(), getCopper();

private:
    int gold{};
    int silver{};
    int copper{};
};