#include "transform_component.h"

#include "constants.h"
#include "sprite_component.h"
#include "entity.h"

transform_component::transform_component(const int pos_x, const int pos_y, const int vel_x, const int vel_y,
                                         const int w, const int h, const int s): position(glm::vec2(pos_x, pos_y)),
                                                                                 velocity(glm::vec2(vel_x, vel_y)),
                                                                                 width(w), height(h), scale(s)
{
}

transform_component::~transform_component()
{
	std::cout << "transform_component destructor called" << std::endl;
}

void transform_component::update(const float delta_time)
{
	update_direction();
	if (is_moving())
		finish_move(delta_time);
}

void transform_component::update_direction()
{
	auto sprite { owner->get_component<sprite_component>() };
	if (is_moving())
	{
		if (velocity.y == -1)
		{
			facing = direction::up;
			sprite->play("up_animation");
			return;
		}
		if (velocity.x == 1)
		{
			facing = direction::right;
			sprite->play("right_animation");
			return;
		}
		if (velocity.y == 1)
		{
			facing = direction::down;
			sprite->play("down_animation");
			return;
		}
		if (velocity.x == -1)
		{
			facing = direction::left;
			sprite->play("left_animation");
		}
	}
	else if (!is_moving())
	{
		if (facing == direction::up)
		{
			sprite->play("up_idle");
			return;
		}
		if (facing == direction::right)
		{
			sprite->play("right_idle");
			return;
		}
		if (facing == direction::down)
		{
			sprite->play("down_idle");
			return;
		}
		if (facing == direction::left)
		{
			sprite->play("left_idle");
		}
	}
}

glm::vec2 transform_component::calculate_new_position(const glm::vec2 current_target)
{
	target_position = velocity;
	target_position.x *= tile_size;
	target_position.y *= tile_size;
	target_position.x += current_target.x;
	target_position.y += current_target.y;
	
	return target_position;
}

void transform_component::move(const glm::vec2 direction)
{
	if (is_moving())
		return;

	velocity = direction;

	target_position = calculate_new_position(position);
}

void transform_component::finish_move(const float delta_time)
{
	if (!is_moving())
		return;

	if (facing == direction::up || facing == direction::down)
	{
		position.y += velocity.y * delta_time * default_speed;
		if (almost_equal(position.y, target_position.y, 10000))
		{
			position = target_position;
			velocity = { 0, 0 };
			target_position = { 0, 0 };
		}
	}
	if (facing == direction::right || facing == direction::left)
	{
		position.x += velocity.x * delta_time * default_speed;
		if (almost_equal(position.x, target_position.x, 10000))
		{
			position = target_position;
			velocity = { 0, 0 };
			target_position = { 0, 0 };
		}
	}

}
