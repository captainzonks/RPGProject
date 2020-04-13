#ifndef ITEM_H
#define ITEM_H

#include "constants.h"

#include <string>
#include <vector>

class item
{
public:

	item_type get_item_type() const { return item_type_; }
	weapon_hand get_weapon_hand() const { return weapon_hand_; }
	armor_type get_armor_type() const { return armor_type_; }
	armor_slot get_armor_slot() const { return armor_slot_; }
	std::string get_name() const { return name_; }
	unsigned get_identifier() const { return identifier_; }
	unsigned get_value() const { return value_; }
	unsigned get_level() const { return level_; }
	unsigned get_weight() const { return weight_; }
	unsigned get_healing_value() const { return healing_value_; }
	unsigned get_hurting_value() const { return hurting_value_; }
	unsigned get_armor_value() const { return armor_value_; }
	std::vector<unsigned> get_damage_dice() const { return damage_dice_; }
	damage_type get_damage_type() const { return damage_type_; }
	
private:
	
	item_type item_type_{ item_type::none };
	weapon_hand weapon_hand_{ weapon_hand::none };
	armor_type armor_type_{ armor_type::none };
	armor_slot armor_slot_{ armor_slot::none };
	std::string name_{};
	unsigned identifier_{};
	unsigned value_{};
	unsigned level_{};
	unsigned weight_{};
	unsigned healing_value_{};
	unsigned hurting_value_{};
	unsigned armor_value_{};
	std::vector<unsigned> damage_dice_{}; // ie, 1d6 or 2d8
	damage_type damage_type_{ damage_type::none };
	
};

#endif