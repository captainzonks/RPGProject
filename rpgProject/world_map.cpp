#include "world_map.h"

#include <iostream>

world_map world_map::world_map_instance_;

void world_map::add_place(location& new_location)
{
	places_.push_back(new_location);
}

void world_map::print_places() const
{
	for (auto& p : places_)
	{
		std::cout << p.get_name() << " (" << p.get_coordinates().at(0) << ", " << p.get_coordinates().at(1) << ")" << std::endl;
	}
}