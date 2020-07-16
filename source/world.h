#ifndef WORLD_H
#define WORLD_H

#include "location.h"

#include <vector>

class world
{
public:
    void add_location();

    [[nodiscard]] std::vector<location> get_world_map() { return world_map_; }

private:
    std::vector<location> world_map_{};
}

#endif