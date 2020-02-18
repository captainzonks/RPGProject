#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Actor
{
public:

	// constructors
	Actor();
	Actor(string name);
	Actor(string name, int health, int xp);
	Actor(string name, int health, int mana, int xp);

	// getters
	string getName();
	int getHealth();
	int getMana();
	int getXP();
	bool livingOrDead();
	void display();
	void displayInventory();

	// actions
	bool subtractHealth(int damage);
	void addXP(int xpGain);
	int rollDice(int dice);
	void addToInventory(string item);

	// moves (temporary)
	void attack(Actor& target);

private:
	// traits
	string name{};
	int health{};
	int mana{};
	int xp{};
	bool isAlive{ true };
	int attackDice{ 10 };

	// inventory
	vector<string> inventory{};
};

