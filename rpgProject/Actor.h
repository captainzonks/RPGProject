#pragma once

#include "Menu.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class Actor
{

public:

	// constructors
	Actor();
	Actor(string name);
	// Actor(string name, int health, int xp);

	// destructors
	virtual ~Actor() {};

	// setters
	void rollStats();

	// getters
	string getName();
	int getHealth(), getXP();
	int getStrength(), getDexterity(), getConstitution(), getIntelligence(), getWisdom(), getCharisma();
	int getStrengthMod(), getDexMod(), getConstMod(), getIntelMod(), getWisdomMod(), getCharMod();
	int getPassivePercetion(), getPassiveInsight(), getPassiveInvestigation();
	bool livingOrDead();
	void display(), displayInventory();

	// actions
	bool subtractHealth(int& damage);
	void addXP(int& xpGain);
	int rollDice(const int& quantity, const int& dice),
		rollDiceIgnoreLowest(const int& quantity, const int& dice);
	void addToInventory(string item);

	// modify stats
	void modifyStrength(const int& modifier),
		modifyDexterity(const int& modifier),
		modifyConstitution(const int& modifier),
		modifyIntelligence(const int& modifier),
		modifyWisdom(const int& modifier),
		modifyCharisma(const int& modifier);

	// moves (temporary)
	void attack(Actor& target);

protected:
	// basic traits
	string name{};
	int health{};
	int xp{};
	bool isAlive{ true };
	int attackDice{ 10 }; // temporary

	// stats
	int strength{};
	int dexterity{};
	int constitution{};
	int intelligence{};
	int wisdom{};
	int charisma{};

	// inventory
	vector<string> inventory{};

};

