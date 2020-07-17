#include "world.h"
#include "location.h"

#include <iostream>

world::~world()
{
    for(auto location : world_map_)
    {
        delete location;
    }
}

void world::add_location(location* new_location)
{
    world_map_.push_back(new_location);
}

void world::print_locations()
{
    std::cout << "####The World####" << std::endl;
    for(auto location : world_map_)
    {
        std::cout << "\n" << location->get_name() << std::endl;
    }
}