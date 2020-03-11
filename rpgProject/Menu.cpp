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
	bool valid_input{ false };

	do
	{
		cout << "Please enter a number: ";
		cin >> choice;

		if (!(valid_input = cin.good()) || choice > decisions || choice < 1)
		{
			cout << "That's not a valid choice." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || choice > decisions || choice < 1);

	return choice;
}