#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "component.h"

#include "./lib/glm/glm.hpp"

class transform_component final
	: public component
{
public:
	glm::vec2 position;
	glm::vec2 velocity;
	int width;
	int height;
	int scale;

	transform_component(const int pos_x,const int pos_y, const int vel_x, const int vel_y, const int w, const int h, const int s)
		: position(glm::vec2(pos_x, pos_y)), velocity(glm::vec2(vel_x, vel_y)), width(w), height(h), scale(s)
	{
		
	}

	~transform_component()
	{
		std::cout << "transform_component destructor called" << std::endl;
	}

	void initialize() override
	{
		
	}

	void update(const float delta_time) override
	{
		position.x += velocity.x * delta_time;
		position.y += velocity.y * delta_time;
	}

	void draw() override
	{
		
	}
};

#endif