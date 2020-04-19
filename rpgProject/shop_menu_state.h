#pragma once

#include <string>

#include "game_state.h"
#include "character.h"

class shop_menu_state final
	: public game_state
{
public:
	void init() override;
	void cleanup() override;

	void pause() override;
	void resume() override;

	void handle_events(game* game) override;
	void update(game* game) override;
	void draw(game* game) override;

	static shop_menu_state* instance()
	{
		return &shop_menu_state_;
	}

	static bool check_price(character& player, const unsigned price)
	{
		if (price > player.access_currency().get_copper())
			return false;
		else
			return true;
	}

protected:
	shop_menu_state() = default;

	unsigned choice_ {};
	static shop_menu_state shop_menu_state_;
	std::vector<std::string> options_ { "Buy Armor", "Buy Weapons", "Back" };
	const std::string name_ { "Shop Menu" };

private:

};

