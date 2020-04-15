#ifndef ROGUE_FUNCTIONS_H
#define ROGUE_FUNCTIONS_H
#include "class_functions.h"

class rogue_functions
	: public class_functions
{
public:
	~rogue_functions() override = default;
	
	static rogue_functions* instance()
	{
		return &rogue_functions_;
	}
	
protected:
	
	rogue_functions() = default;
	static rogue_functions rogue_functions_;
	
};

#endif
