#include "WeaponShopMenu.h"

void WeaponShopMenu::Init()
{
}

void WeaponShopMenu::Cleanup()
{
}

void WeaponShopMenu::Pause()
{
}

void WeaponShopMenu::Resume()
{
}

void WeaponShopMenu::HandleEvents(Game* game)
{
}

void WeaponShopMenu::Update(Game* game)
{
}

void WeaponShopMenu::Draw(Game* game)
{
	cout << "----" << this->name << "----" << endl;
	int count{ 1 };
	for (int i{}; i != options.size(); ++i)
	{
		cout << count << ") " << options[i] << endl;
		count++;
	}
	cout << "----";
	for (int i{}; i != this->name.length(); i++)
	{
		cout << "-";
	}
	cout << "----" << endl;

	bool valid_input{ false };

	do
	{
		cout << "Please enter a number: ";
		cin >> choice;

		if (!(valid_input = cin.good()) || choice > options.size() || choice < 1)
		{
			cout << "That's not a valid choice." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || choice > options.size() || choice < 1);
}
