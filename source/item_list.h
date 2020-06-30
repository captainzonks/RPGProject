#ifndef ITEM_LIST_H
#define ITEM_LIST_H
#include <memory>

#include "item.h"
#include "constants.h"

namespace item_list
{
	class item_maker
	{
	public:

		// Sword of Infinite Fury
		[[nodiscard]] std::unique_ptr<item> make_sword_of_infinite_fury() const
		{
			const std::vector<unsigned> damage_dice {2,6};
			auto sword_of_infinite_fury = std::make_unique<item>(
				item_type::weapon,
				resources::none,
				weapon_hand::main,
				armor_type::none,
				armor_slot::none,
				"Sword of Infinite Fury",
				00001,
				25000,
				1,
				5,
				0,
				0,
				damage_dice,
				damage_type::piercing
			);

			return std::move(sword_of_infinite_fury);
		}

		static item_maker* instance()
		{
			return &item_maker_instance_;
		}

	protected:
		item_maker() = default;
		static item_maker item_maker_instance_;
	};

	
}

#endif
