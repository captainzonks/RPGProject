#pragma once

#include "GameState.h"

class ShopMenuState :
	public GameState
{
public:
	void Init();
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(Game* game);
	void Update(Game* game);
	void Draw(Game* game);

	static ShopMenuState* Instance()
	{
		return &m_ShopMenuState;
	}

	bool CheckPrice(Actor& player, int price) const
	{
		if (price > player.myCurrency.GetCopper())
			return false;
		else
			return true;
	}

protected:
	ShopMenuState() {}

	int choice{};
	static ShopMenuState m_ShopMenuState;
	std::vector<std::string> options{ "Buy Armor", "Buy Weapons", "Back" };
	const std::string name{ "Shop Menu" };

private:
	// bool states
	bool helmetState{};
	bool chestState{};
	bool legsState{};
	bool handsState{};
	bool bootsState{};
	bool swordLState{};
	bool swordRState{};
	bool rangedState{};
	bool shieldState{};

	// pointers
	std::unique_ptr<Helmet> helmet_ptr{ nullptr };
	std::unique_ptr<Chest> chest_ptr{ nullptr };
	std::unique_ptr<Legs> legs_ptr{ nullptr };
	std::unique_ptr<Hands> hands_ptr{ nullptr };
	std::unique_ptr<Boots> boots_ptr{ nullptr };
	std::unique_ptr<Sword> sword_ptr{ nullptr };
	std::unique_ptr<ShortBow> bow_ptr{ nullptr };
	std::unique_ptr<Shield> shield_ptr{ nullptr };
	std::unique_ptr<Potion> potion_ptr{ nullptr };
};

