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
	const auto it = find_if(owners_.begin(), owners_.end(),
		[&not_owner](const character& obj)
	{
		return obj.access_attributes().get_name() == not_owner.access_attributes().get_name();
	});

	if (it != owners_.end())
		owners_.erase(owners_.begin(), it);
}

void location::remove_visitors(character& not_visitor)
{
	const auto it = find_if(visitors_.begin(), visitors_.end(),
		[&not_visitor](const character& obj)
	{
		return obj.access_attributes().get_name() == not_visitor.access_attributes().get_name();
	});

	if (it != visitors_.end())
		visitors_.erase(visitors_.begin(), it);
}