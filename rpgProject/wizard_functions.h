#ifndef WIZARD_FUNCTIONS_H
#define WIZARD_FUNCTIONS_H
#include "class_functions.h"

class wizard_functions final
	: public class_functions
{
public:
	~wizard_functions() override = default;
	
	static wizard_functions* instance()
	{
		return &wizard_functions_;
	}
	
protected:
	wizard_functions() = default;
	static wizard_functions wizard_functions_;
};

#endif
