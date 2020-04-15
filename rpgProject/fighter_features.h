#ifndef FIGHTER_FEATURES_H
#define FIGHTER_FEATURES_H

#include "class_features.h"

class fighter_features
	: class_features
{
public:
	fighter_features() = default;
	~fighter_features() override = default;

	void set_fighting_style(fighting_style fighting_style);
	
	[[nodiscard]]fighting_style get_fighting_style() const { return fighting_style_; }

private:
	fighting_style fighting_style_ {};
	int hit_die_ {10};
	int starting_hit_points_ {10};

	std::vector<abilities> saving_throws_ {abilities::strength, abilities::constitution};
	std::vector<armor_type> armor_proficiences_ {armor_type::light_armor, armor_type::medium_armor, armor_type::heavy_armor};
	std::vector<weapon_proficiency> weapon_proficiences_ {weapon_proficiency::simple, weapon_proficiency::martial};
};

#endif
