#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <SDL.h>
#include <string>

#include "entity.h"
#include "component.h"
#include "transform_component.h"

class collider_component :
	public component
{
public:
	std::string collider_tag;
	SDL_Rect collider;
	SDL_Rect source_rectangle;
	SDL_Rect destination_rectangle;
	transform_component* transform;

	collider_component(const std::string& collider_tag, int x, int y, int width, int height);

	void initialize() override;

	void update(float delta_time) override;
};

#endif