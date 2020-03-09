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

	Upgrader(player);
	
}

bool Narrator::CheckPrice(std::shared_ptr<Actor> player, int price)
{
	if (price > player->myCurrency.GetCopper())
		return false;
	else
		return true;
}

void Narrator::Upgrader(std::shared_ptr<Actor> actor)
{
	// false(0) for new purchase, true(1) for upgrading
	bool helmetState{ actor->myUpgrades.HelmetEquipped() };
	bool chestState{ actor->myUpgrades.ChestEquipped() };
	bool legsState{ actor->myUpgrades.LegsEquipped() };
	bool handsState{ actor->myUpgrades.HandsEquipped() };
	bool bootsState{ actor->myUpgrades.BootsEquipped() };

	// the pointers
	std::unique_ptr<Helmet> helmet_ptr{ nullptr };
	std::unique_ptr<Chest> chest_ptr{ nullptr };
	std::unique_ptr<Legs> legs_ptr{ nullptr };
	std::unique_ptr<Hands> hands_ptr{ nullptr };
	std::unique_ptr<Boots> boots_ptr{ nullptr };

	std::cout << "ARMOR FOR SALE" << std::endl;
	std::cout << "--------------" << std::endl;

	if (!helmetState)
	{
		// new helmet
		helmet_ptr = std::make_unique<Helmet>();
		std::cout << "1) Buy " << helmet_ptr->GetName() <<
			" : Level " << helmet_ptr->GetLevel() <<
			" : " << helmet_ptr->GetValue() / 100 << " gold" << std::endl;
	}
	else
	{
		// upgrade helmet
		std::cout << "1) Upgrade to Helmet Level " <<
			actor->myUpgrades.GetHelmetLevel() + 1 <<
			" : " << (actor->myUpgrades.helmet->GetValue() + 150) / 100 <<
			" gold " << std::endl;
	}
	if (!chestState)
	{
		// new chest
		chest_ptr = std::make_unique<Chest>();
		std::cout << "2) Buy " << chest_ptr->GetName() <<
			" : Level " << chest_ptr->GetLevel() <<
			" : " << chest_ptr->GetValue() / 100 << " gold" << std::endl;
	}
	else
	{
		// upgrade chest
		std::cout << "2) Upgrade to Chest Armor Level " <<
			actor->myUpgrades.GetChestLevel() + 1 <<
			" : " << (actor->myUpgrades.chest->GetValue() + 300) / 100 <<
			" gold " << std::endl;
	}
	if (!legsState)
	{
		// new legs
		legs_ptr = std::make_unique<Legs>();
		std::cout << "3) Buy " << legs_ptr->GetName() <<
			" : Level " << legs_ptr->GetLevel() <<
			" : " << legs_ptr->GetValue() / 100 << " gold" << std::endl;
	}
	else
	{
		// upgrade legs
		std::cout << "3) Upgrade to Leg Armor Level " <<
			actor->myUpgrades.GetLegsLevel() + 1 <<
			" : " << (actor->myUpgrades.legs->GetValue() + 250) / 100 <<
			" gold " << std::endl;
	}
	if (!handsState)
	{
		// new hands
		hands_ptr = std::make_unique<Hands>();
		std::cout << "4) Buy " << hands_ptr->GetName() <<
			" : Level " << hands_ptr->GetLevel() <<
			" : " << hands_ptr->GetValue() / 100 << " gold" << std::endl;
	}
	else
	{
		// upgrade hands
		std::cout << "4) Upgrade to Gauntlets Level " <<
			actor->myUpgrades.GetHandsLevel() + 1 <<
			" : " << (actor->myUpgrades.hands->GetValue() + 150) / 100 <<
			" gold " << std::endl;
	}
	if (!bootsState)
	{
		// new boots
		boots_ptr = std::make_unique<Boots>();
		std::cout << "5) Buy " << boots_ptr->GetName() <<
			" : Level " << boots_ptr->GetLevel() <<
			" : " << boots_ptr->GetValue() / 100 << " gold" << std::endl;
	}
	else
	{
		// upgrade boots
		std::cout << "5) Upgrade to Boots Level " <<
			actor->myUpgrades.GetBootsLevel() + 1 <<
			" : " << (actor->myUpgrades.boots->GetValue() + 200) / 100 <<
			" gold " << std::endl;
	}
	std::cout << "0) - Exit" << std::endl;
	std::cout << "Please enter a number: " << std::endl;
	int choice{};
	cin >> choice;
	switch (choice)
	{
	case 1:
		if (!helmetState)
		{
			if (CheckPrice(actor, helmet_ptr->GetValue()))
			{
				actor->myCurrency.subtractMoney(helmet_ptr->GetValue());
				actor->EquipHelmet(std::move(helmet_ptr));
				cout << "Obtained a Helmet!" << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
		else
		{
			if (CheckPrice(actor, actor->myUpgrades.helmet->GetValue() + 150))
			{
				actor->myCurrency.subtractMoney(actor->myUpgrades.helmet->GetValue() + 150);
				actor->myUpgrades.helmet->UpgradeArmor();
				cout << "Upgraded Helmet to Level " << actor->myUpgrades.GetHelmetLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 2:
		if (!chestState)
		{
			if (CheckPrice(actor, chest_ptr->GetValue()))
			{
				actor->myCurrency.subtractMoney(chest_ptr->GetValue());
				actor->EquipChest(std::move(chest_ptr));
				cout << "Obtained Chest Armor!" << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
		else
		{
			if (CheckPrice(actor, actor->myUpgrades.chest->GetValue() + 300))
			{
				actor->myCurrency.subtractMoney(actor->myUpgrades.chest->GetValue() + 300);
				actor->myUpgrades.chest->UpgradeArmor();
				cout << "Upgraded Chest Armor to Level " << actor->myUpgrades.GetChestLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 3:
		if (!legsState)
		{
			if (CheckPrice(actor, legs_ptr->GetValue()))
			{
				actor->EquipLegs(std::move(legs_ptr));
				cout << "Obtained Leg Armor!" << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
		else
		{
			if (CheckPrice(actor, actor->myUpgrades.legs->GetValue() + 250))
			{
				actor->myCurrency.subtractMoney(actor->myUpgrades.legs->GetValue() + 250);
				actor->myUpgrades.legs->UpgradeArmor();
				cout << "Upgraded Leg Armor to Level " << actor->myUpgrades.GetLegsLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 4:
		if (!handsState)
		{
			if (CheckPrice(actor, hands_ptr->GetValue()))
			{
				actor->EquipHands(std::move(hands_ptr));
				cout << "Obtained Gauntlets!" << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
		else
		{
			if (CheckPrice(actor, actor->myUpgrades.hands->GetValue() + 150))
			{
				actor->myCurrency.subtractMoney(actor->myUpgrades.hands->GetValue() + 150);
				actor->myUpgrades.hands->UpgradeArmor();
				cout << "Upgraded Gauntlets to Level " << actor->myUpgrades.GetHandsLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 5:
		if (!bootsState)
		{
			if (CheckPrice(actor, boots_ptr->GetValue()))
			{
				actor->EquipBoots(std::move(boots_ptr));
				cout << "Obtained Boots!" << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
		else
		{
			if (CheckPrice(actor, actor->myUpgrades.boots->GetValue() + 200))
			{
				actor->myCurrency.subtractMoney(actor->myUpgrades.boots->GetValue() + 200);
				actor->myUpgrades.boots->UpgradeArmor();
				cout << "Upgraded Boots to Level " << actor->myUpgrades.GetBootsLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 0:
		break;
	default:
		cout << "Invalid entry" << endl;
		break;
	}
}
