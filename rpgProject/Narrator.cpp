//#include "Narrator.h"
//
//void Narrator::StartGreeting()
//{
//	cout << "=======================" << endl;
//	cout << "Welcome to RPG game " << version << endl;
//	cout << "-----------------------" << endl;
//}
//
//actor* Narrator::CharacterCreator()
//{
//	cout << "\nLet's create a character!" << endl;
//
//	cout << "\nWhat race_ are you?" << endl;
//	int choice_{};
//	string race_;
//	std::unique_ptr<Menu> tempMenu = std::make_unique<Menu>();
//	std::unique_ptr<int> const decisions = std::make_unique<int>(4);
//	std::unique_ptr<vector<string>> tempDecisions = std::make_unique<vector<string>>(std::initializer_list<string>({ "Human", "Dwarf", "Elf", "Halfling" }));
//	choice_ = tempMenu->print_menu(*decisions, *tempDecisions);
//
//	switch (choice_)
//	{
//	case 1:
//		race_ = "Human";
//		break;
//	case 2:
//		race_ = "Dwarf";
//		break;
//	case 3:
//		race_ = "Elf";
//		break;
//	case 4:
//		race_ = "Halfling";
//		break;
//	default:
//		break;
//	}
//
//	string name_{};
//	cout << "\nWhat's your name_? ";
//	cin >> name_;
//
//	cout << "\nWhat class are you?" << endl;
//	choice_ = 0;
//	std::unique_ptr<Menu> tempMenu2 = std::make_unique<Menu>();
//	std::unique_ptr<int> const decisions2 = std::make_unique<int>(1);
//	std::unique_ptr<vector<string>> tempDecisions2 = std::make_unique<vector<string>>(std::initializer_list<string>({ "Fighter" }));
//	choice_ = tempMenu2->print_menu(*decisions2, *tempDecisions2);
//
//	actor* new_player{ nullptr };
//
//	switch (choice_)
//	{
//	case 1:
//		new_player = new Fighter(name_, race_);
//		break;
//	default:
//		break;
//	}
//
//	return new_player;
//}
//
//void Narrator::BuySomething(actor& player)
//{
//	cout << "Welcome to fantasy shop " << version << "!" << endl;
//	cout << "=============================" << endl;
//	cout << "What would you like to purchase?" << endl;
//
//	Upgrader(player);
//}
//
//bool Narrator::CheckPrice(actor& player, int price) const
//{
//	if (price > player.myCurrency.get_copper())
//		return false;
//	else
//		return true;
//}
//
//void Narrator::Upgrader(actor& actor)
//{
//	// false(0) for new purchase, true(1) for upgrading
//	bool helmetState{ actor.myUpgrades.HelmetEquipped() };
//	bool chestState{ actor.myUpgrades.ChestEquipped() };
//	bool legsState{ actor.myUpgrades.LegsEquipped() };
//	bool handsState{ actor.myUpgrades.HandsEquipped() };
//	bool bootsState{ actor.myUpgrades.BootsEquipped() };
//	bool swordLState{ actor.myUpgrades.WeaponLEquipped() };
//	bool swordRState{ actor.myUpgrades.WeaponREquipped() };
//	bool rangedState{ actor.myUpgrades.RangedWeaponEquipped() };
//	bool shieldState{ actor.myUpgrades.ShieldEquipped() };
//
//	// the pointers
//	std::unique_ptr<Helmet> helmet_ptr{ nullptr };
//	std::unique_ptr<Chest> chest_ptr{ nullptr };
//	std::unique_ptr<Legs> legs_ptr{ nullptr };
//	std::unique_ptr<Hands> hands_ptr{ nullptr };
//	std::unique_ptr<Boots> boots_ptr{ nullptr };
//	std::unique_ptr<Sword> sword_ptr{ nullptr };
//	std::unique_ptr<ShortBow> bow_ptr{ nullptr };
//	std::unique_ptr<Shield> shield_ptr{ nullptr };
//	std::unique_ptr<Potion> potion_ptr{ nullptr };
//
//	// armor
//	std::cout << "\nARMOR FOR SALE" << std::endl;
//	std::cout << "--------------" << std::endl;
//	if (!helmetState)
//	{
//		int tempSilver{}, tempCopper{};
//		// new helmet
//		helmet_ptr = std::make_unique<Helmet>();
//		std::cout << "1) Buy " << helmet_ptr->get_name() <<
//			" : Level " << helmet_ptr->get_level() <<
//			" :";
//		display_price(helmet_ptr->GetValue());
//	}
//	else
//	{
//		// upgrade helmet
//		std::cout << "1) Upgrade to Helmet Level " <<
//			actor.myUpgrades.GetHelmetLevel() + 1 <<
//			" :";
//		display_price(actor.myUpgrades.helmet->GetValue() + 150);
//	}
//	if (!chestState)
//	{
//		// new chest
//		chest_ptr = std::make_unique<Chest>();
//		std::cout << "2) Buy " << chest_ptr->get_name() <<
//			" : Level " << chest_ptr->get_level() <<
//			" :";
//		display_price(chest_ptr->GetValue());
//	}
//	else
//	{
//		// upgrade chest
//		std::cout << "2) Upgrade to Chest Armor Level " <<
//			actor.myUpgrades.GetChestLevel() + 1 <<
//			" :";
//		display_price(actor.myUpgrades.chest->GetValue() + 300);
//	}
//	if (!legsState)
//	{
//		// new legs
//		legs_ptr = std::make_unique<Legs>();
//		std::cout << "3) Buy " << legs_ptr->get_name() <<
//			" : Level " << legs_ptr->get_level() <<
//			" :";
//		display_price(legs_ptr->GetValue());
//	}
//	else
//	{
//		// upgrade legs
//		std::cout << "3) Upgrade to Leg Armor Level " <<
//			actor.myUpgrades.GetLegsLevel() + 1 <<
//			" :";
//		display_price(actor.myUpgrades.legs->GetValue() + 250);
//	}
//	if (!handsState)
//	{
//		// new hands
//		hands_ptr = std::make_unique<Hands>();
//		std::cout << "4) Buy " << hands_ptr->get_name() <<
//			" : Level " << hands_ptr->get_level() <<
//			" :";
//		display_price(hands_ptr->GetValue());
//	}
//	else
//	{
//		// upgrade hands
//		std::cout << "4) Upgrade to Gauntlets Level " <<
//			actor.myUpgrades.GetHandsLevel() + 1 <<
//			" :";
//		display_price(actor.myUpgrades.hands->GetValue() + 150);
//	}
//	if (!bootsState)
//	{
//		// new boots
//		boots_ptr = std::make_unique<Boots>();
//		std::cout << "5) Buy " << boots_ptr->get_name() <<
//			" : Level " << boots_ptr->get_level() <<
//			" :";
//		display_price(boots_ptr->GetValue());
//	}
//	else
//	{
//		// upgrade boots
//		std::cout << "5) Upgrade to Boots Level " <<
//			actor.myUpgrades.GetBootsLevel() + 1 <<
//			" :";
//		display_price(actor.myUpgrades.boots->GetValue() + 200);
//	}
//	if (!shieldState && !rangedState)
//	{
//		// new shield
//		shield_ptr = std::make_unique<Shield>();
//		std::cout << "6) Buy " << shield_ptr->get_name() <<
//			" : Level " << shield_ptr->get_level() <<
//			" :";
//		display_price(shield_ptr->GetValue());
//	}
//	else if (shieldState)
//	{
//		// upgrade shield
//		std::cout << "6) Upgrade to Shield Level " <<
//			actor.myUpgrades.GetShieldLevel() + 1 <<
//			" :";
//		display_price(actor.myUpgrades.shield->GetValue() + 200);
//	}
//	/*********************************************************************/
//
//	// WEAPONS
//	std::cout << "\nWEAPONS FOR SALE" << std::endl;
//	std::cout << "--------------" << std::endl;
//	if (!swordLState && !rangedState)
//	{
//		// new swordL
//		sword_ptr = std::make_unique<Sword>();
//		std::cout << "7) Buy " << sword_ptr->get_name() <<
//			"(L) : Level " << sword_ptr->get_level() <<
//			" :";
//		display_price(sword_ptr->GetValue());
//	}
//	if ((swordLState && !shieldState) && !swordRState && !rangedState)
//	{
//		// new swordR
//		sword_ptr = std::make_unique<Sword>();
//		std::cout << "8) Buy " << sword_ptr->get_name() <<
//			"(R) : Level " << sword_ptr->get_level() <<
//			" :";
//		display_price(sword_ptr->GetValue());
//	}
//	else if (swordLState || swordRState)
//	{
//		// upgrade swordL
//		if (swordLState)
//		{
//			std::cout << "7) Upgrade to Sword Level " <<
//				actor.myUpgrades.GetWeaponLLevel() + 1 <<
//				"(L) :";
//			display_price(actor.myUpgrades.weaponL->GetValue() + 250);
//		}
//		// upgrade swordR
//		if (swordRState)
//		{
//			std::cout << "8) Upgrade to Sword Level " <<
//				actor.myUpgrades.GetWeaponLLevel() + 1 <<
//				"(R) :";
//			display_price(actor.myUpgrades.weaponR->GetValue() + 250);
//		}
//	}
//	if (!rangedState)
//	{
//		// new shortbow
//		bow_ptr = std::make_unique<ShortBow>();
//		std::cout << "9) Buy " << bow_ptr->get_name() <<
//			" : Level " << bow_ptr->get_level() <<
//			" : ";
//		display_price(bow_ptr->GetValue());
//	}
//	else
//	{
//		// upgrade shortbow
//		if (rangedState)
//		{
//			std::cout << "9) Upgrade to Shortbow Level " <<
//				actor.myUpgrades.GetRangedWeaponLevel() + 1 <<
//				" :";
//			display_price(actor.myUpgrades.rangedWeapon->GetValue() + 200);
//		}
//
//	}
//	/*********************************************************************/
//
//	// POTIONS
//	std::cout << "\nPOTIONS FOR SALE" << std::endl;
//	std::cout << "--------------" << std::endl;
//	// new consumable
//	int randomHeals{ rand() % 12 + 2 };
//	potion_ptr = std::make_unique<Potion>(randomHeals);
//	std::cout << "10) Buy a " << potion_ptr->get_name() <<
//		" :";
//	display_price(potion_ptr->GetValue());
//	/****************************************************************/
//
//	std::cout << "--------------" << std::endl;
//	std::cout << "0) - Exit" << std::endl;
//	std::cout << "Please enter a number: " << std::endl;
//	int choice_{};
//	cin >> choice_;
//	switch (choice_)
//	{
//	case 1:
//		if (!helmetState)
//		{
//			if (CheckPrice(actor, helmet_ptr->GetValue()))
//			{
//				actor.myCurrency.subtract_money(helmet_ptr->GetValue());
//				actor.EquipHelmet(std::move(helmet_ptr));
//				cout << "Obtained a Helmet!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.helmet->GetValue() + 150))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.helmet->GetValue() + 150);
//				actor.myUpgrades.helmet->UpgradeArmor();
//				cout << "Upgraded Helmet to Level " << actor.myUpgrades.GetHelmetLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 2:
//		if (!chestState)
//		{
//			if (CheckPrice(actor, chest_ptr->GetValue()))
//			{
//				actor.myCurrency.subtract_money(chest_ptr->GetValue());
//				actor.EquipChest(std::move(chest_ptr));
//				cout << "Obtained Chest Armor!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.chest->GetValue() + 300))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.chest->GetValue() + 300);
//				actor.myUpgrades.chest->UpgradeArmor();
//				cout << "Upgraded Chest Armor to Level " << actor.myUpgrades.GetChestLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 3:
//		if (!legsState)
//		{
//			if (CheckPrice(actor, legs_ptr->GetValue()))
//			{
//				actor.EquipLegs(std::move(legs_ptr));
//				cout << "Obtained Leg Armor!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.legs->GetValue() + 250))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.legs->GetValue() + 250);
//				actor.myUpgrades.legs->UpgradeArmor();
//				cout << "Upgraded Leg Armor to Level " << actor.myUpgrades.GetLegsLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 4:
//		if (!handsState)
//		{
//			if (CheckPrice(actor, hands_ptr->GetValue()))
//			{
//				actor.EquipHands(std::move(hands_ptr));
//				cout << "Obtained Gauntlets!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.hands->GetValue() + 150))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.hands->GetValue() + 150);
//				actor.myUpgrades.hands->UpgradeArmor();
//				cout << "Upgraded Gauntlets to Level " << actor.myUpgrades.GetHandsLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 5:
//		if (!bootsState)
//		{
//			if (CheckPrice(actor, boots_ptr->GetValue()))
//			{
//				actor.EquipBoots(std::move(boots_ptr));
//				cout << "Obtained Boots!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.boots->GetValue() + 200))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.boots->GetValue() + 200);
//				actor.myUpgrades.boots->UpgradeArmor();
//				cout << "Upgraded Boots to Level " << actor.myUpgrades.GetBootsLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 6:
//		if (!shieldState && !rangedState && !(swordLState && swordRState))
//		{
//			if (CheckPrice(actor, shield_ptr->GetValue()))
//			{
//				actor.EquipShield(std::move(shield_ptr));
//				cout << "Obtained a Shield!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else if (rangedState || (swordLState && swordRState))
//		{
//			std::cout << "You don't have room to equip a Shield." << std::endl;
//			break;
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.shield->GetValue() + 200))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.shield->GetValue() + 200);
//				actor.myUpgrades.shield->UpgradeArmor();
//				cout << "Upgraded Shield to Level " << actor.myUpgrades.GetShieldLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 7:
//		if (!swordLState && !rangedState && !(swordRState && shieldState))
//		{
//			if (CheckPrice(actor, sword_ptr->GetValue()))
//			{
//				actor.EquipWeaponL(std::move(sword_ptr));
//				cout << "Obtained a Sword!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else if (rangedState || (swordRState && shieldState))
//		{
//			std::cout << "You don't have room to equip a Sword." << std::endl;
//			break;
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.weaponL->GetValue() + 200))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.weaponL->GetValue() + 200);
//				actor.myUpgrades.weaponL->UpgradeWeapon();
//				cout << "Upgraded Sword to Level " << actor.myUpgrades.GetWeaponLLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 8:
//		if (!swordRState && !rangedState && !(swordLState && shieldState))
//		{
//			if (CheckPrice(actor, sword_ptr->GetValue()))
//			{
//				actor.EquipWeaponR(std::move(sword_ptr));
//				cout << "Obtained a Sword!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else if (rangedState || (swordLState && shieldState))
//		{
//			std::cout << "You don't have room to equip a Sword." << std::endl;
//			break;
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.weaponR->GetValue() + 200))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.weaponR->GetValue() + 200);
//				actor.myUpgrades.weaponR->UpgradeWeapon();
//				cout << "Upgraded Sword to Level " << actor.myUpgrades.GetWeaponRLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 9:
//		if (!rangedState && !(swordLState && swordRState) && !(swordLState && shieldState) && !(swordRState && shieldState))
//		{
//			if (CheckPrice(actor, bow_ptr->GetValue()))
//			{
//				actor.EquipRanged(std::move(bow_ptr));
//				cout << "Obtained a Shortbow!" << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else if (!rangedState && (swordLState || swordRState || shieldState))
//		{
//			std::cout << "You don't have room to carry a bow." << std::endl;
//			break;
//		}
//		else
//		{
//			if (CheckPrice(actor, actor.myUpgrades.rangedWeapon->GetValue() + 200))
//			{
//				actor.myCurrency.subtract_money(actor.myUpgrades.rangedWeapon->GetValue() + 200);
//				actor.myUpgrades.rangedWeapon->UpgradeWeapon();
//				cout << "Upgraded Shortbow to Level " << actor.myUpgrades.GetRangedWeaponLevel() << endl;
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//	case 10:
//		if (actor.myInventory.get_capacity() != 0)
//		{
//			if (CheckPrice(actor, potion_ptr->GetValue()))
//			{
//				actor.myCurrency.subtract_money(potion_ptr->GetValue());
//				cout << "Obtained a +" << potion_ptr->GetHealthValue() << "HP Healing Potion!" << endl;
//				actor.myInventory.add_potion_to_inventory(std::move(potion_ptr));
//				break;
//			}
//			else
//			{
//				std::cout << "You can't afford that." << std::endl;
//				break;
//			}
//		}
//		else
//		{
//			std::cout << "You don't have enough bag space." << std::endl;
//			break;
//		}
//	case 0:
//		break;
//	default:
//		cout << "Invalid entry" << endl;
//		break;
//	}
//}
//
//void Narrator::display_price(const int copper_) const
//{
//	int tempGold{}, tempSilver{}, tempCopper{ copper_ };
//	tempGold = copper_ / 100;
//	tempCopper %= 100;
//	tempSilver = tempCopper / 10;
//	tempCopper %= 10;
//	if (tempGold != 0)
//		cout << " " << tempGold << "g";
//	if (tempSilver != 0)
//		cout << " " << tempSilver << "s";
//	if (tempCopper != 0)
//		cout << " " << tempCopper << "c";
//	cout << endl;
//}
//
//int Narrator::GetPlayerAverageLevel(actor& player) const
//{
//	int average{player.get_average_item_level()};
//
//	return average;
//}
