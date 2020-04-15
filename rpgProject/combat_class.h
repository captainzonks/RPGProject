#ifndef COMBAT_CLASS_H
#define COMBAT_CLASS_H

#include <map>
#include <vector>

#include "constants.h"

class class_features;
class class_functions;
class fighter_features;
class fighter_functions;
class wizard_functions;
class rogue_functions;

class combat_class
{
public:

	explicit combat_class(unsigned class_choice);
	virtual ~combat_class();

	void build_class(unsigned class_choice);
	std::map<character_class, int>& get_my_class() { return my_class_; }
	
	void attack();
	
private:
	// class & level storage
	std::map<character_class, int> my_class_ {};

	// class function pointers
	fighter_functions* my_fighter_functions_ {};
	wizard_functions* my_wizard_functions_ {};
	rogue_functions* my_rogue_functions_ {};

	// class features pointers
	fighter_features* my_fighter_features_ {};
	
};

#endif