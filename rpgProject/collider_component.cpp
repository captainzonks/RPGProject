#include "collider_component.h"

#include "game.h"

collider_component::collider_component(const std::string& collider_tag, const int x, const int y, const int width, const int height)
{
	this->collider_tag = collider_tag;
	this->collider = { x, y, width, height };
}

void collider_component::initialize()
{
	if (owner->has_component<transform_component>())
	{
		transform = owner->get_component<transform_component>();
		source_rectangle = { 0, 0, transform->width, transform->height };
		destination_rectangle = { collider.x, collider.y, collider.w, collider.h };
	}
}

void collider_component::update(float delta_time)
{
	collider.x = static_cast<int>(transform->position.x);
	collider.y = static_cast<int>(transform->position.y);
	collider.w = transform->width * transform->scale;
	collider.h = transform->height * transform->scale;
	destination_rectangle.x = collider.x - game::camera.x;
	destination_rectangle.y = collider.y - game::camera.y;
}
