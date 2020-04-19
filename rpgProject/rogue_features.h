#ifndef ROGUE_FEATURES_H
#define ROGUE_FEATURES_H

#include <iostream>

#include "class_features.h"
#include "rogue_functions.h"

class rogue_features final
	: public class_features
{
public:
	rogue_features() = default;
	~rogue_features() override { std::cout << "rogue features destructor called" << std::endl; }

	[[nodiscard]] int get_hit_die() override { return hit_die_; }
	[[nodiscard]] int get_starting_hit_points() override { return starting_hit_points_; }
	[[nodiscard]] int get_level() override { return level_; }

	[[nodiscard]] std::vector<abilities> get_saving_throws() const override { return saving_throws_; }
	[[nodiscard]] std::vector<armor_type> get_armor_proficiences() const override { return armor_proficiences_; }
	[[nodiscard]] std::vector<weapon_proficiency> get_weapon_proficiencies() const override { return weapon_proficiences_; }
	[[nodiscard]] rogue_functions* access_rogue_functions() const { return my_rogue_functions_; }
	
private:
	int hit_die_ {8};
	int starting_hit_points_ {8};
	int level_ {1};

	std::vector<abilities> saving_throws_ {abilities::dexterity, abilities::intelligence};
	std::vector<armor_type> armor_proficiences_ {armor_type::light_armor};
	std::vector<weapon_proficiency> weapon_proficiences_ {weapon_proficiency::simple}; // fix this
	rogue_functions* my_rogue_functions_ {rogue_functions::instance()};
	
};

#endif