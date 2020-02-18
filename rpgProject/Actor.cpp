#include "Actor.h"

#include <iostream>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

Actor::Actor()
{
	cout << "What is your name? ";
	cin >> name;
	health = 100;
	xp = 0;
}

Actor::Actor(std::string name)
{
	this->name = name;
	health = 100;
	xp = 0;
}

Actor::Actor(std::string name, int health, int xp)
{
	this->name = name;
	this->health = health;
	this->xp = xp;
}

Actor::Actor(std::string name, int health, int mana, int xp)
{
	this->name = name;
	this->health = health;
	this->mana = mana;
	this->xp = xp;
}

std::string Actor::getName()
{
	return name;
}

int Actor::getHealth()
{
	return health;
}

int Actor::getMana()
{
	return mana;
}

int Actor::getXP()
{
	return xp;
}

bool Actor::livingOrDead()
{
	return isAlive;
}

void Actor::display()
{
	cout << endl;
	cout << "====" << this->getName() << "====" << endl;
	cout << "   " << this->getHealth() << " HP" << endl;
	cout << "   " << this->getMana() << " Mana" << endl;
	cout << "   " << this->getXP() << " XP" << endl;
	cout << "====";
	for (char c : this->getName())
	{
		cout << "=";
	}
	cout << "====\n" << endl;
}

void Actor::displayInventory()
{
	cout << "\n" << this->getName() << "'s Inventory" << endl;
	cout << "============" << endl;
	int counter{ 1 };
	for (auto i : inventory)
	{
		cout << counter << ": " << i << endl;
	}
	cout << "============" << endl;
}

bool Actor::subtractHealth(int damage)
{
	// TODO handling of death won't be here

	bool isAlive{ true };
	if (this->health > 0)
	{
		this->health -= damage;
		if (this->health <= 0)
		{
			isAlive = false;
		}
	}
	else
	{
		isAlive = false;
	}

	return isAlive;
}

void Actor::addXP(int xpGain)
{
	this->xp += xpGain;
}

int Actor::rollDice(int dice)
{
	srand((unsigned int)time(NULL));
	int result{ rand() % dice + 1 };
	return result;
}

void Actor::addToInventory(string item)
{
	inventory.push_back(item);
	cout << "\nAdded " << item << " to inventory!" << endl;
}

void Actor::attack(Actor& target)
{
	// TODO this is a basic randomly generated attack concept
	// eventual goal is to have unique attacks in separate methods (or classes)
	
	cout << this->name << " is attacking " << target.name << endl;
	int damage{ rollDice(attackDice) };
	if (target.subtractHealth(damage))
	{
		cout << this->name << " did " << damage << " damage to " << target.name << "!" << endl;
	}
	else if (!target.subtractHealth(damage))
	{
		cout << this->name << " killed " << target.name << " with " << damage << " damage!" << endl;
		target.isAlive = false;
	}
}

