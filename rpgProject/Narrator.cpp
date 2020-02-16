#include "Narrator.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void Narrator::startGreeting()
{
	cout << "=======================" << endl;
	cout << "Welcome to RPG Game " << version << endl;
	cout << "-----------------------" << endl;
}

void Narrator::characterCreator()
{
	cout << "\nLet's create a character!" << endl;
}

void Narrator::encounter(Actor* player)
{
	// TODO should an encounter be handled here?
	// (probably not)

	cout << "An enemy approaches!" << endl;
	Actor enemy{ "Enemy", 1, 0 };
	char choice{};
	while (tolower(choice) != 'y' && tolower(choice) != 'n')
	{
		cout << "Engage? ";
		cin >> choice;
		switch (tolower(choice))
		{
		case 'y':
		{
			player->attack(&enemy);
			enemy.display();
			break;
		}
		case 'n':
		{
			cout << "You ran away!" << endl;
			break;
		}
		default:
		{
			cout << "That is not recognized input." << endl;
			break;
		}
		}
	}
}
