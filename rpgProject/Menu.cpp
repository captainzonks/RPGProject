#include "Menu.h"

int Menu::printMenu(const int& decisions, const string* listOfDecisions[])
{
	int count{ 1 };
	for (int i{}; i != decisions; ++i)
	{
		cout << count << ") " << (*listOfDecisions)[i] << endl;
		count++;
	}
	return choiceHandler(decisions);
}

int Menu::choiceHandler(const int& decisions)
{
	int choice{};
	while (choice == 0 || (choice < decisions && choice > decisions))
	{
		cout << "Please enter a number: ";
		cin >> choice;
		if (choice < 1 || choice > decisions)
		{
			cout << "That's not a valid choice." << endl;
			choice = 0;
		}
		else
			return choice;
	}
	return choice;
}