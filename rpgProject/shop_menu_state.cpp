#include "ShopMenuState.h"

ShopMenuState ShopMenuState::m_ShopMenuState;

void ShopMenuState::Init()
{
	cout << "Welcome to fantasy shop " << version << "!" << endl;
	cout << "=============================" << endl;
	cout << "What would you like to purchase?" << endl;
}

void ShopMenuState::Cleanup()
{
}

void ShopMenuState::Pause()
{
}

void ShopMenuState::Resume()
{
}

void ShopMenuState::HandleEvents(Game* game)
{
	if (choice != 0)
	{
		switch (choice)
		{
		case 1:
			// helmet
			if (!helmetState)
			{
				if (CheckPrice(*game->player, helmet_ptr->GetValue()))
				{
					game->player->myCurrency.SubtractMoney(helmet_ptr->GetValue());
					game->player->EquipHelmet(std::move(helmet_ptr));
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
				if (CheckPrice(*game->player, game->player->myUpgrades.helmet->GetValue() + 150))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.helmet->GetValue() + 150);
					game->player->myUpgrades.helmet->UpgradeArmor();
					cout << "Upgraded Helmet to Level " << game->player->myUpgrades.GetHelmetLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 2:
			// chest
			if (!chestState)
			{
				if (CheckPrice(*game->player, chest_ptr->GetValue()))
				{
					game->player->myCurrency.SubtractMoney(chest_ptr->GetValue());
					game->player->EquipChest(std::move(chest_ptr));
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
				if (CheckPrice(*game->player, game->player->myUpgrades.chest->GetValue() + 300))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.chest->GetValue() + 300);
					game->player->myUpgrades.chest->UpgradeArmor();
					cout << "Upgraded Chest Armor to Level " << game->player->myUpgrades.GetChestLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 3:
			// legs
			if (!legsState)
			{
				if (CheckPrice(*game->player, legs_ptr->GetValue()))
				{
					game->player->EquipLegs(std::move(legs_ptr));
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
				if (CheckPrice(*game->player, game->player->myUpgrades.legs->GetValue() + 250))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.legs->GetValue() + 250);
					game->player->myUpgrades.legs->UpgradeArmor();
					cout << "Upgraded Leg Armor to Level " << game->player->myUpgrades.GetLegsLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 4:
			// hands
			if (!handsState)
			{
				if (CheckPrice(*game->player, hands_ptr->GetValue()))
				{
					game->player->EquipHands(std::move(hands_ptr));
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
				if (CheckPrice(*game->player, game->player->myUpgrades.hands->GetValue() + 150))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.hands->GetValue() + 150);
					game->player->myUpgrades.hands->UpgradeArmor();
					cout << "Upgraded Gauntlets to Level " << game->player->myUpgrades.GetHandsLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 5:
			// boots
			if (!bootsState)
			{
				if (CheckPrice(*game->player, boots_ptr->GetValue()))
				{
					game->player->EquipBoots(std::move(boots_ptr));
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
				if (CheckPrice(*game->player, game->player->myUpgrades.boots->GetValue() + 200))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.boots->GetValue() + 200);
					game->player->myUpgrades.boots->UpgradeArmor();
					cout << "Upgraded Boots to Level " << game->player->myUpgrades.GetBootsLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 6:
			// shield
			if (!shieldState && !rangedState && !(swordLState && swordRState))
			{
				if (CheckPrice(*game->player, shield_ptr->GetValue()))
				{
					game->player->EquipShield(std::move(shield_ptr));
					cout << "Obtained a Shield!" << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
			else if (rangedState || (swordLState && swordRState))
			{
				std::cout << "You don't have room to equip a Shield." << std::endl;
				break;
			}
			else
			{
				if (CheckPrice(*game->player, game->player->myUpgrades.shield->GetValue() + 200))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.shield->GetValue() + 200);
					game->player->myUpgrades.shield->UpgradeArmor();
					cout << "Upgraded Shield to Level " << game->player->myUpgrades.GetShieldLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 7:
			// swordL
			if (!swordLState && !rangedState && !(swordRState && shieldState))
			{
				if (CheckPrice(*game->player, sword_ptr->GetValue()))
				{
					game->player->EquipWeaponL(std::move(sword_ptr));
					cout << "Obtained a Sword!" << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
			else if (rangedState || (swordRState && shieldState))
			{
				std::cout << "You don't have room to equip a Sword." << std::endl;
				break;
			}
			else
			{
				if (CheckPrice(*game->player, game->player->myUpgrades.weaponL->GetValue() + 200))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.weaponL->GetValue() + 200);
					game->player->myUpgrades.weaponL->UpgradeWeapon();
					cout << "Upgraded Sword to Level " << game->player->myUpgrades.GetWeaponLLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 8:
			// swordR
			if (!swordRState && !rangedState && !(swordLState && shieldState))
			{
				if (CheckPrice(*game->player, sword_ptr->GetValue()))
				{
					game->player->EquipWeaponR(std::move(sword_ptr));
					cout << "Obtained a Sword!" << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
			else if (rangedState || (swordLState && shieldState))
			{
				std::cout << "You don't have room to equip a Sword." << std::endl;
				break;
			}
			else
			{
				if (CheckPrice(*game->player, game->player->myUpgrades.weaponR->GetValue() + 200))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.weaponR->GetValue() + 200);
					game->player->myUpgrades.weaponR->UpgradeWeapon();
					cout << "Upgraded Sword to Level " << game->player->myUpgrades.GetWeaponRLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 9:
			// ranged
			if (!rangedState && (!swordLState && !swordRState && !shieldState))
			{
				if (CheckPrice(*game->player, bow_ptr->GetValue()))
				{
					game->player->EquipRanged(std::move(bow_ptr));
					cout << "Obtained a Shortbow!" << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
			else if (swordLState || swordRState || shieldState)
			{
				std::cout << "You don't have room to carry a bow." << std::endl;
				break;
			}
			else
			{
				if (CheckPrice(*game->player, game->player->myUpgrades.rangedWeapon->GetValue() + 200))
				{
					game->player->myCurrency.SubtractMoney(game->player->myUpgrades.rangedWeapon->GetValue() + 200);
					game->player->myUpgrades.rangedWeapon->UpgradeWeapon();
					cout << "Upgraded Shortbow to Level " << game->player->myUpgrades.GetRangedWeaponLevel() << endl;
					break;
				}
				else
				{
					std::cout << "You can't afford that." << std::endl;
					break;
				}
			}
		case 10:
			// healing consumable
			if (game->player->myInventory.GetCapacity() != 0)
			{
				if (CheckPrice(*game->player, potion_ptr->GetValue()))
				{
					game->player->myCurrency.SubtractMoney(potion_ptr->GetValue());
					cout << "Obtained a +" << potion_ptr->GetHealthValue() << "HP Healing Potion!" << endl;
					game->player->myInventory.AddPotionToInventory(std::move(potion_ptr));
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
		case 11:
			game->PopState();
			break;
		default:
			break;
		}
	}
}

void ShopMenuState::Update(Game* game)
{
	helmetState = game->player->myUpgrades.HelmetEquipped();
	chestState = game->player->myUpgrades.ChestEquipped();
	legsState = game->player->myUpgrades.LegsEquipped();
	handsState = game->player->myUpgrades.HandsEquipped();
	bootsState = game->player->myUpgrades.BootsEquipped();
	swordLState = game->player->myUpgrades.WeaponLEquipped();
	swordRState = game->player->myUpgrades.WeaponREquipped();
	rangedState = game->player->myUpgrades.RangedWeaponEquipped();
	shieldState = game->player->myUpgrades.ShieldEquipped();
}

void ShopMenuState::Draw(Game* game)
{
	// armor
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
			game->player->myUpgrades.GetHelmetLevel() + 1 <<
			" :";
		DisplayPrice(game->player->myUpgrades.helmet->GetValue() + 150);
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
			game->player->myUpgrades.GetChestLevel() + 1 <<
			" :";
		DisplayPrice(game->player->myUpgrades.chest->GetValue() + 300);
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
			game->player->myUpgrades.GetLegsLevel() + 1 <<
			" :";
		DisplayPrice(game->player->myUpgrades.legs->GetValue() + 250);
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
			game->player->myUpgrades.GetHandsLevel() + 1 <<
			" :";
		DisplayPrice(game->player->myUpgrades.hands->GetValue() + 150);
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
			game->player->myUpgrades.GetBootsLevel() + 1 <<
			" :";
		DisplayPrice(game->player->myUpgrades.boots->GetValue() + 200);
	}
	if (!shieldState && !rangedState && (!game->player->IsDualWielding()))
	{
		// new shield
		shield_ptr = std::make_unique<Shield>();
		std::cout << "6) Buy " << shield_ptr->GetName() <<
			" : Level " << shield_ptr->GetLevel() <<
			" :";
		DisplayPrice(shield_ptr->GetValue());
	}
	else if (shieldState)
	{
		// upgrade shield
		std::cout << "6) Upgrade to Shield Level " <<
			game->player->myUpgrades.GetShieldLevel() + 1 <<
			" :";
		DisplayPrice(game->player->myUpgrades.shield->GetValue() + 200);
	}
	/*********************************************************************/

	// WEAPONS
	std::cout << "\nWEAPONS FOR SALE" << std::endl;
	std::cout << "--------------" << std::endl;
	if (!swordLState && !rangedState)
	{
		// new swordL
		sword_ptr = std::make_unique<Sword>();
		std::cout << "7) Buy " << sword_ptr->GetName() <<
			"(L) : Level " << sword_ptr->GetLevel() <<
			" :";
		DisplayPrice(sword_ptr->GetValue());
	}
	if ((swordLState && !shieldState) && !swordRState && !rangedState)
	{
		// new swordR
		sword_ptr = std::make_unique<Sword>();
		std::cout << "8) Buy " << sword_ptr->GetName() <<
			"(R) : Level " << sword_ptr->GetLevel() <<
			" :";
		DisplayPrice(sword_ptr->GetValue());
	}
	else if (swordLState || swordRState)
	{
		// upgrade swordL
		if (swordLState)
		{
			std::cout << "7) Upgrade to Sword Level " <<
				game->player->myUpgrades.GetWeaponLLevel() + 1 <<
				"(L) :";
			DisplayPrice(game->player->myUpgrades.weaponL->GetValue() + 250);
		}
		// upgrade swordR
		if (swordRState)
		{
			std::cout << "8) Upgrade to Sword Level " <<
				game->player->myUpgrades.GetWeaponRLevel() + 1 <<
				"(R) :";
			DisplayPrice(game->player->myUpgrades.weaponR->GetValue() + 250);
		}
	}
	if (!rangedState && !swordLState && !swordRState && !shieldState)
	{
		// new shortbow
		bow_ptr = std::make_unique<ShortBow>();
		std::cout << "9) Buy " << bow_ptr->GetName() <<
			" : Level " << bow_ptr->GetLevel() <<
			" : ";
		DisplayPrice(bow_ptr->GetValue());
	}
	else
	{
		// upgrade shortbow
		if (rangedState)
		{
			std::cout << "9) Upgrade to Shortbow Level " <<
				game->player->myUpgrades.GetRangedWeaponLevel() + 1 <<
				" :";
			DisplayPrice(game->player->myUpgrades.rangedWeapon->GetValue() + 200);
		}

	}
	/*********************************************************************/

	// POTIONS
	std::cout << "\nPOTIONS FOR SALE" << std::endl;
	std::cout << "--------------" << std::endl;
	// new consumable
	int randomHeals{ rand() % 12 + 2 };
	potion_ptr = std::make_unique<Potion>(randomHeals);
	std::cout << "10) Buy a " << potion_ptr->GetName() <<
		" :";
	DisplayPrice(potion_ptr->GetValue());
	/****************************************************************/

	std::cout << "--------------" << std::endl;
	std::cout << "11) - Back" << std::endl;

	choice = 0;
	bool valid_input{ false };

	do
	{
		cout << "\nPlease enter a number: ";
		cin >> choice;

		if (!(valid_input = cin.good()) || choice > 11 || choice < 1)
		{
			cout << "That's not a valid choice." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (!valid_input || choice > 11 || choice < 1);
}
