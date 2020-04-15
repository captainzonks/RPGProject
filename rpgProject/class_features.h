#ifndef CLASS_FEATURES_H
#define CLASS_FEATURES_H
#include <vector>

#include "constants.h"

class class_features
{
public:
	class_features() = default;
	virtual ~class_features() = default;

	virtual int get_hit_die() = 0;
	virtual int get_starting_hit_points() = 0;

	virtual std::vector<armor_type> get_armor_proficiences() = 0;
	virtual std::vector<weapon_proficiency> get_weapon_proficiencies() = 0;
	virtual std::vector<abilities> get_saving_throws() = 0;
	
protected:

};

#endif
