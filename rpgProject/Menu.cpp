#include "Menu.h"

int Menu::PrintMenu(const int& decisions, const vector<string>& listOfDecisions)
{
	cout << "--------" << endl;
	int count{ 1 };
	for (int i{}; i != decisions; ++i)
	{
		cout << count << ") " << listOfDecisions[i] << endl;
		count++;
	}
	cout << "--------" << endl;
	return choiceHandler(decisions);
}

int Menu::UpgradeMenu(const int& decisions, const vector<std::unique_ptr<Item>>& listOfDecisions)
{
	cout << "--------" << endl;
	int count{ 1 };
	for (int i{}; i != decisions; ++i)
	{
		cout << count << ") " << *(listOfDecisions.at(i)) << " : " << listOfDecisions.at(i)->GetValue() / 100 << " gold" << endl;
		count++;
	}
	cout << "--------" << endl;
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