#include "Narrator.h"

void Narrator::StartGreeting()
{
	cout << "=======================" << endl;
	cout << "Welcome to RPG Game " << version << endl;
	cout << "-----------------------" << endl;
}

std::shared_ptr<Actor> Narrator::CharacterCreator()
{
	cout << "\nLet's create a character!" << endl;

	cout << "What are you?" << endl;
	int choice{};
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(4);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Human", "Dwarf", "Elf", "Halfling" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	string name{};
	cout << "What's your name? ";
	cin >> name;

	std::shared_ptr<Actor> new_player{ nullptr };

	switch (choice)
	{
	case 1:
		new_player = std::make_shared<Human>(name);
		break;
	case 2:
		new_player = std::make_shared<Dwarf>(name);
		break;
	case 3:
		new_player = std::make_shared<Elf>(name);
		break;
	case 4:
		new_player = std::make_shared<Halfling>(name);
		break;
	default:
		break;
	}

	return new_player;
}

void Narrator::BuySomething(std::shared_ptr<Actor> player)
{
	cout << "Welcome to fantasy shop " << version << "!" << endl;
	cout << "=============================" << endl;
	cout << "What would you like to purchase?" << endl;

	std::unique_ptr<Sword> sword = std::make_unique<Sword>();
	std::unique_ptr<Shield> shield = std::make_unique<Shield>();

	cout << "1) " << *sword << " : " << (sword->GetValue() / 100) << " gold" << endl;
	cout << "2) " << *shield << " : " << (shield->GetValue() / 100) << " gold" << endl;
	cout << "--------------" << endl;
	int choice{};
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (CheckPrice(player, sword->GetValue()))
		{
			player->myInventory.GetWeapon(std::move(sword));
			cout << "Obtained a sword!" << endl;
			break;
		}
		else
		{
			std::cout << "You can't afford that." << std::endl;
			break;
		}
	case 2:
		if (CheckPrice(player, shield->GetValue()))
		{
			player->myInventory.GetArmor(std::move(shield));
			cout << "Obtained a shield!" << endl;
			break;
		}
		else
		{
			std::cout << "You can't afford that." << std::endl;
			break;
		}
	default:
		cout << "Invalid entry" << endl;
		break;
	}
}

bool Narrator::CheckPrice(std::shared_ptr<Actor> player, int price)
{
	if (price > player->myCurrency.GetCopper())
		return false;
	else
		return true;
}
