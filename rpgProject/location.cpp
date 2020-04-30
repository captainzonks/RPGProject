#include "location.h"

void location::update()
{	
}

void location::add_owners(character& owner)
{
	owners_.push_back(owner);
}

void location::add_visitors(character& visitor)
{
	visitors_.push_back(visitor);
}

void location::remove_owners(character& not_owner)
{

}

void location::remove_visitors(character& not_visitor)
{

}