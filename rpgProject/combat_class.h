#ifndef COMBAT_CLASS_H
#define COMBAT_CLASS_H

#include "constants.h"

class combat_class
{
public:

	combat_class() = default;
	~combat_class() = default;
	
	void attack();
	
private:

	character_class my_class_ {};
	
};

#endif