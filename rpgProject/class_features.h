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
	virtual int get_level() = 0;

	[[nodiscard]] virtual std::vector<armor_type> get_armor_proficiences() const = 0;
	[[nodiscard]] virtual std::vector<weapon_proficiency> get_weapon_proficiencies() const = 0;
	[[nodiscard]] virtual std::vector<abilities> get_saving_throws() const = 0;
	
protected:

};

#endif
