#ifndef WIZARD_FEATURES_H
#define WIZARD_FEATURES_H

#include <iostream>

#include "class_features.h"
#include "wizard_functions.h"

class wizard_features final
	: public class_features
{
public:
	wizard_features() = default;
	~wizard_features() override { std::cout << "wizard features destructor called" << std::endl; }
	
	[[nodiscard]] int get_hit_die() override { return hit_die_; }
	[[nodiscard]] int get_starting_hit_points() override { return starting_hit_points_; }
	[[nodiscard]] int get_level() override { return level_; }
	
	[[nodiscard]] std::vector<abilities> get_saving_throws() const override { return saving_throws_; }
	[[nodiscard]] std::vector<armor_type> get_armor_proficiences() const override { return armor_proficiences_; }
	[[nodiscard]] std::vector<weapon_proficiency> get_weapon_proficiencies() const override { return weapon_proficiences_; }
	[[nodiscard]] wizard_functions* access_wizard_functions() const { return my_wizard_functions_; }
	
private:

	int hit_die_ {6};
	int starting_hit_points_ {6};
	int level_ {1};

	std::vector<abilities> saving_throws_ {abilities::intelligence, abilities::wisdom};
	std::vector<armor_type> armor_proficiences_ {armor_type::none};
	std::vector<weapon_proficiency> weapon_proficiences_ {weapon_proficiency::none}; // fix this
	wizard_functions* my_wizard_functions_ {wizard_functions::instance()};
};

#endif
