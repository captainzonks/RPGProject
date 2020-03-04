#pragma once

#include <map>
#include <string>

class Fighter
{
public:

	Fighter();

	~Fighter();

	int attack(int decision);

private:

	std::map<std::string, int> listOfAttacks = {
		{"Weapon", 1},
		{"Punch", 2},
		{"Kick", 3}
	};

};

