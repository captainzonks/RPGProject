#include "I_Display.h"

ostream& operator<<(ostream& os, const I_Display& obj)
{
	obj.print(os);
	return os;
}