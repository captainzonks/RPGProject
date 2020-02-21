#pragma once

#include <vector>
#include <string>

class Fighter
{
public:

	Fighter();

	~Fighter();

	int attack(int decision);

private:

	std::vector<std::string> listOfAttacks{ "Attack with Sword", "Punch", "Kick" };

	/*
	Create a vector of types of attacks
	Create a vector of definitions for those attacks
	link their indexes so that an attack can be picked
	and then the definition called for mathematical results
	*/

};

