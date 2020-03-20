#include "Narrator.h"

void Narrator::StartGreeting()
{
	cout << "=======================" << endl;
	cout << "Welcome to RPG Game " << version << endl;
	cout << "-----------------------" << endl;
}

Actor* Narrator::CharacterCreator()
{
	cout << "\nLet's create a character!" << endl;

	cout << "\nWhat race are you?" << endl;
	int choice{};
	string race;
	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions = std::make_unique<int>(4);
	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Human", "Dwarf", "Elf", "Halfling" }));
	choice = tempMenu->PrintMenu(*decisions, *tempDecisions);

	switch (choice)
	{
	case 1:
		race = "Human";
		break;
	case 2:
		race = "Dwarf";
		break;
	case 3:
		race = "Elf";
		break;
	case 4:
		race = "Halfling";
		break;
	default:
		break;
	}

	string name{};
	cout << "\nWhat's your name? ";
	cin >> name;

	cout << "\nWhat class are you?" << endl;
	choice = 0;
	std::unique_ptr<Menu> tempMenu2 = std::make_unique<Menu>();
	std::unique_ptr<int> const decisions2 = std::make_unique<int>(1);
	std::unique_ptr<vector<string>> tempDecisions2 = std::make_unique<vector<string>>(std::initializer_list<string>({ "Fighter" }));
	choice = tempMenu2->PrintMenu(*decisions2, *tempDecisions2);

	Actor* new_player{ nullptr };

	switch (choice)
	{
	case 1:
		new_player = new Fighter(name, race);
		break;
	default:
		break;
	}

	return new_player;
}

void Narrator::BuySomething(Actor& player)
{
	cout << "Welcome to fantasy shop " << version << "!" << endl;
	cout << "=============================" << endl;
	cout << "What would you like to purchase?" << endl;

	Upgrader(player);
}

bool Narrator::CheckPrice(Actor& player, int price) const
{
	if (price > player.myCurrency.GetCopper())
		return false;
	else
		return true;
}

void Narrator::Upgrader(Actor& actor)
{
	// false(0) for new purchase, true(1) for upgrading
	bool helmetState{ actor.myUpgrades.HelmetEquipped() };
	bool chestState{ actor.myUpgrades.ChestEquipped() };
	bool legsState{ actor.myUpgrades.LegsEquipped() };
	bool handsState{ actor.myUpgrades.HandsEquipped() };
	bool bootsState{ actor.myUpgrades.BootsEquipped() };
	bool swordState{ actor.myUpgrades.WeaponLEquipped() };
	bool shieldState{ actor.myUpgrades.ShieldEquipped() };

	// the pointers
	std::unique_ptr<Helmet> helmet_ptr{ nullptr };
	std::unique_ptr<Chest> chest_ptr{ nullptr };
	std::unique_ptr<Legs> legs_ptr{ nullptr };
	std::unique_ptr<Hands> hands_ptr{ nullptr };
	std::unique_ptr<Boots> boots_ptr{ nullptr };
	std::unique_ptr<Sword> sword_ptr{ nullptr };
	std::unique_ptr<Shield> shield_ptr{ nullptr };
	std::unique_ptr<Potion> potion_ptr{ nullptr };

	// ARMOR
	std::cout << "\nARMOR FOR SALE" << std::endl;
	std::cout << "--------------" << std::endl;
	if (!helmetState)
	{
		int tempSilver{}, tempCopper{};
		// new helmet
		helmet_ptr = std::make_unique<Helmet>();
		std::cout << "1) Buy " << helmet_ptr->GetName() <<
			" : Level " << helmet_ptr->GetLevel() <<
			" :";
		DisplayPrice(helmet_ptr->GetValue());
	}
	else
	{
		// upgrade helmet
		std::cout << "1) Upgrade to Helmet Level " <<
			actor.myUpgrades.GetHelmetLevel() + 1 <<
			" :";
		DisplayPrice(actor.myUpgrades.helmet->GetValue() + 150);
	}
	if (!chestState)
	{
		// new chest
		chest_ptr = std::make_unique<Chest>();
		std::cout << "2) Buy " << chest_ptr->GetName() <<
			" : Level " << chest_ptr->GetLevel() <<
			" :";
		DisplayPrice(chest_ptr->GetValue());
	}
	else
	{
		// upgrade chest
		std::cout << "2) Upgrade to Chest Armor Level " <<
			actor.myUpgrades.GetChestLevel() + 1 <<
			" :";
		DisplayPrice(actor.myUpgrades.chest->GetValue() + 300);
	}
	if (!legsState)
	{
		// new legs
		legs_ptr = std::make_unique<Legs>();
		std::cout << "3) Buy " << legs_ptr->GetName() <<
			" : Level " << legs_ptr->GetLevel() <<
			" :";
		DisplayPrice(legs_ptr->GetValue());
	}
	else
	{
		// upgrade legs
		std::cout << "3) Upgrade to Leg Armor Level " <<
			actor.myUpgrades.GetLegsLevel() + 1 <<
			" :";
		DisplayPrice(actor.myUpgrades.legs->GetValue() + 250);
	}
	if (!handsState)
	{
		// new hands
		hands_ptr = std::make_unique<Hands>();
		std::cout << "4) Buy " << hands_ptr->GetName() <<
			" : Level " << hands_ptr->GetLevel() <<
			" :";
		DisplayPrice(hands_ptr->GetValue());
	}
	else
	{
		// upgrade hands
		std::cout << "4) Upgrade to Gauntlets Level " <<
			actor.myUpgrades.GetHandsLevel() + 1 <<
			" :";
		DisplayPrice(actor.myUpgrades.hands->GetValue() + 150);
	}
	if (!bootsState)
	{
		// new boots
		boots_ptr = std::make_unique<Boots>();
		std::cout << "5) Buy " << boots_ptr->GetName() <<
			" : Level " << boots_ptr->GetLevel() <<
			" :";
		DisplayPrice(boots_ptr->GetValue());
	}
	else
	{
		// upgrade boots
		std::cout << "5) Upgrade to Boots Level " <<
			actor.myUpgrades.GetBootsLevel() + 1 <<
			" :";
		DisplayPrice(actor.myUpgrades.boots->GetValue() + 200);
	}
	if (!shieldState)
	{
		// new shield
		shield_ptr = std::make_unique<Shield>();
		std::cout << "6) Buy " << shield_ptr->GetName() <<
			" : Level " << shield_ptr->GetLevel() <<
			" :";
		DisplayPrice(shield_ptr->GetValue());
	}
	else
	{
		// upgrade shield
		std::cout << "6) Upgrade to Shield Level " <<
			actor.myUpgrades.GetShieldLevel() + 1 <<
			" :";
		DisplayPrice(actor.myUpgrades.shield->GetValue() + 200);
	}
	/*********************************************************************/

	// WEAPONS
	std::cout << "\nWEAPONS FOR SALE" << std::endl;
	std::cout << "--------------" << std::endl;
	if (!swordState)
	{
		// new sword
		sword_ptr = std::make_unique<Sword>();
		std::cout << "7) Buy " << sword_ptr->GetName() <<
			" : Level " << sword_ptr->GetLevel() <<
			" :";
		DisplayPrice(sword_ptr->GetValue());
	}
	else
	{
		// upgrade sword
		std::cout << "7) Upgrade to Sword Level " <<
			actor.myUpgrades.GetWeaponLLevel() + 1 <<
			" :";
		DisplayPrice(actor.myUpgrades.weaponL->GetValue() + 250);
	}
	/*********************************************************************/

	// POTIONS
	std::cout << "\nPOTIONS FOR SALE" << std::endl;
	std::cout << "--------------" << std::endl;
	// new potion
	int randomHeals{ rand() % 12 + 2 };
	potion_ptr = std::make_unique<Potion>(randomHeals);
	std::cout << "8) Buy a " << potion_ptr->GetName() <<
		" :";
	DisplayPrice(potion_ptr->GetValue());
	/****************************************************************/

	std::cout << "--------------" << std::endl;
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
				actor.myCurrency.SubtractMoney(helmet_ptr->GetValue());
				actor.EquipHelmet(std::move(helmet_ptr));
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
			if (CheckPrice(actor, actor.myUpgrades.helmet->GetValue() + 150))
			{
				actor.myCurrency.SubtractMoney(actor.myUpgrades.helmet->GetValue() + 150);
				actor.myUpgrades.helmet->UpgradeArmor();
				cout << "Upgraded Helmet to Level " << actor.myUpgrades.GetHelmetLevel() << endl;
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
				actor.myCurrency.SubtractMoney(chest_ptr->GetValue());
				actor.EquipChest(std::move(chest_ptr));
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
			if (CheckPrice(actor, actor.myUpgrades.chest->GetValue() + 300))
			{
				actor.myCurrency.SubtractMoney(actor.myUpgrades.chest->GetValue() + 300);
				actor.myUpgrades.chest->UpgradeArmor();
				cout << "Upgraded Chest Armor to Level " << actor.myUpgrades.GetChestLevel() << endl;
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
				actor.EquipLegs(std::move(legs_ptr));
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
			if (CheckPrice(actor, actor.myUpgrades.legs->GetValue() + 250))
			{
				actor.myCurrency.SubtractMoney(actor.myUpgrades.legs->GetValue() + 250);
				actor.myUpgrades.legs->UpgradeArmor();
				cout << "Upgraded Leg Armor to Level " << actor.myUpgrades.GetLegsLevel() << endl;
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
				actor.EquipHands(std::move(hands_ptr));
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
			if (CheckPrice(actor, actor.myUpgrades.hands->GetValue() + 150))
			{
				actor.myCurrency.SubtractMoney(actor.myUpgrades.hands->GetValue() + 150);
				actor.myUpgrades.hands->UpgradeArmor();
				cout << "Upgraded Gauntlets to Level " << actor.myUpgrades.GetHandsLevel() << endl;
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
				actor.EquipBoots(std::move(boots_ptr));
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
			if (CheckPrice(actor, actor.myUpgrades.boots->GetValue() + 200))
			{
				actor.myCurrency.SubtractMoney(actor.myUpgrades.boots->GetValue() + 200);
				actor.myUpgrades.boots->UpgradeArmor();
				cout << "Upgraded Boots to Level " << actor.myUpgrades.GetBootsLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 6:
		if (!shieldState)
		{
			if (CheckPrice(actor, shield_ptr->GetValue()))
			{
				actor.EquipShield(std::move(shield_ptr));
				cout << "Obtained a Shield!" << endl;
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
			if (CheckPrice(actor, actor.myUpgrades.shield->GetValue() + 200))
			{
				actor.myCurrency.SubtractMoney(actor.myUpgrades.shield->GetValue() + 200);
				actor.myUpgrades.shield->UpgradeArmor();
				cout << "Upgraded Shield to Level " << actor.myUpgrades.GetShieldLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 7:
		if (!swordState)
		{
			if (CheckPrice(actor, sword_ptr->GetValue()))
			{
				actor.EquipWeaponL(std::move(sword_ptr));
				cout << "Obtained a Sword!" << endl;
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
			if (CheckPrice(actor, actor.myUpgrades.weaponL->GetValue() + 200))
			{
				actor.myCurrency.SubtractMoney(actor.myUpgrades.weaponL->GetValue() + 200);
				actor.myUpgrades.weaponL->UpgradeWeapon();
				cout << "Upgraded Sword to Level " << actor.myUpgrades.GetWeaponLLevel() << endl;
				break;
			}
			else
			{
				std::cout << "You can't afford that." << std::endl;
				break;
			}
		}
	case 8:
		if (actor.myInventory.GetCapacity() != 0)
		{
			if (CheckPrice(actor, potion_ptr->GetValue()))
			{
				actor.myCurrency.SubtractMoney(potion_ptr->GetValue());
				cout << "Obtained a +" << potion_ptr->GetHealthValue() << "HP Healing Potion!" << endl;
				actor.myInventory.AddPotionToInventory(std::move(potion_ptr));
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
			std::cout << "You don't have enough bag space." << std::endl;
			break;
		}
	case 0:
		break;
	default:
		cout << "Invalid entry" << endl;
		break;
	}
}

void Narrator::DisplayPrice(const int copper) const
{
	int tempGold{}, tempSilver{}, tempCopper{ copper };
	tempGold = copper / 100;
	tempCopper %= 100;
	tempSilver = tempCopper / 10;
	tempCopper %= 10;
	if (tempGold != 0)
		cout << " " << tempGold << "g";
	if (tempSilver != 0)
		cout << " " << tempSilver << "s";
	if (tempCopper != 0)
		cout << " " << tempCopper << "c";
	cout << endl;
}

int Narrator::GetPlayerAverageLevel(Actor& player) const
{
	int average{player.GetAverageItemLevel()};

	return average;
}
