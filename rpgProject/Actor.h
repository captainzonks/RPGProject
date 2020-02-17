#pragma once

#include <string>

class Actor
{
public:

	// constructors
	Actor();
	Actor(std::string name);
	Actor(std::string name, int health, int xp);
	Actor(std::string name, int health, int mana, int xp);

	// getters
	std::string getName();
	int getHealth();
	int getMana();
	int getXP();
	bool livingOrDead();
	void display();

	// actions
	bool subtractHealth(int damage);
	void addXP(int xpGain);
	int rollDice(int dice);

	// moves (temporary)
	void attack(Actor* target);

private:
	std::string name{};
	int health{};
	int mana{};
	int xp{};
	bool isAlive{ true };
	int attackDice{ 10 };

};

