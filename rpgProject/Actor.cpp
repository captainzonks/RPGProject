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

void Actor::attack(Actor* target)
{
	// TODO this is a basic randomly generated attack concept
	// eventual goal is to have unique attacks in separate methods (or classes)
	
	cout << this->name << " is attacking " << (*target).name << endl;
	srand((unsigned int)time(NULL));
	int damage{ rand() % 10 + 1 };
	if ((*target).subtractHealth(damage))
	{
		cout << this->name << " did " << damage << " damage to " << (*target).name << "!" << endl;
	}
	else if (!(*target).subtractHealth(damage))
	{
		cout << this->name << " killed " << (*target).name << "!" << endl;
	}
}

