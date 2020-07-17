#ifndef SPACIAL_COMPONENT_H
#define SPACIAL_COMPONENT_H

#include <iostream>

#include "component.h"
#include "constants.h"

class spacial_component final
    : public component
{
public:
    spacial_component() = default;
    ~spacial_component() { std::cout << "spacial_component destructor called" << std::endl; }

    void initialize() override {}
    void update() override {}
    void render() override {}

private:
    coordinates my_coordinates_{};
};

#endif