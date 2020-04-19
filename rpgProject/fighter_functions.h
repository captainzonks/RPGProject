#ifndef FIGHTER_FUNCTIONS_H
#define FIGHTER_FUNCTIONS_H
#include "class_functions.h"

class fighter_functions final
	: public class_functions
{
public:
	~fighter_functions() override = default;

	static fighter_functions* instance()
	{
		return &fighter_functions_;
	}
	
protected:
	
	fighter_functions() = default;
	static fighter_functions fighter_functions_;
	
};

#endif
