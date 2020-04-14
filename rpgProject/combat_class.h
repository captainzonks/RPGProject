#ifndef COMBAT_CLASS_H
#define COMBAT_CLASS_H

#include "constants.h"

class fighter_functions;
class wizard_functions;
class rogue_functions;

class combat_class
{
public:

	explicit combat_class(unsigned class_choice);
	virtual ~combat_class();
	
	void attack();
	
private:

	character_class my_class_ {};

	// class function pointers
	fighter_functions* fighter_;
	wizard_functions* wizard_;
	rogue_functions* rogue_;
	
};

#endif