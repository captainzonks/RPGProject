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
	if (move_time_ > 0)
	{
		move_time_--;

		switch(facing)
		{
		case direction::up:
		case direction::down:
			position.y += velocity.y * delta_time * default_speed;
			break;
		case direction::right:
		case direction::left:
			position.x += velocity.x * delta_time * default_speed;
		default:
			break;
		}

		if (move_time_ == 0)
			is_moving_ = false;
	}
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
}

void transform_component::move(const glm::vec2 direction)
{
	is_moving_ = true;
	velocity = direction;
	update_direction();
	move_time_ = frames_to_cross_one_tile_;
}