#ifndef FIGHTER_FEATURES_H
#define FIGHTER_FEATURES_H

#include <iostream>

#include "class_features.h"
#include "fighter_functions.h"

class fighter_features final
	: public class_features
{
public:
	fighter_features(const fighter_features& other) = default;

	fighter_features() = default;
	~fighter_features() override { std::cout << "fighter features destructor called" << std::endl; }

	void pick_fighting_style();
	void set_fighting_style(fighting_style fighting_style);

	[[nodiscard]] int get_hit_die() override { return hit_die_; }
	[[nodiscard]] int get_starting_hit_points() override { return starting_hit_points_; }
	[[nodiscard]] int get_level() override { return level_; }
	
	[[nodiscard]] fighting_style get_fighting_style() const { return fighting_style_; }
	[[nodiscard]] std::vector<abilities> get_saving_throws() const override { return saving_throws_; }
	[[nodiscard]] std::vector<armor_type> get_armor_proficiences() const override { return armor_proficiences_; }
	[[nodiscard]] std::vector<weapon_proficiency> get_weapon_proficiencies() const override { return weapon_proficiences_; }
	[[nodiscard]] fighter_functions* access_fighter_functions() const { return my_fighter_functions_; }
	
	void display_class_information();
	
	static void print_twf_def();
	static void print_protection_def();
	static void print_gwf_def();
	static void print_dueling_def();
	static void print_defense_def();
	static void print_archery_def();
	
private:
	fighting_style fighting_style_ {};
	int hit_die_ {10};
	int starting_hit_points_ {10};
	int level_ {1};

	std::vector<abilities> saving_throws_ {abilities::strength, abilities::constitution};
	std::vector<armor_type> armor_proficiences_ {armor_type::light_armor, armor_type::medium_armor, armor_type::heavy_armor};
	std::vector<weapon_proficiency> weapon_proficiences_ {weapon_proficiency::simple, weapon_proficiency::martial};
	fighter_functions* my_fighter_functions_ {fighter_functions::instance()};
};

#endif
