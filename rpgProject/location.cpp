#include "location.h"

void location::update()
{	
}

void location::add_owners(entity& owner)
{
	owners_.push_back(owner);
}

void location::add_visitors(entity& visitor)
{
	visitors_.push_back(visitor);
}

void location::remove_owners(entity& not_owner)
{

}

void location::remove_visitors(entity& not_visitor)
{

}