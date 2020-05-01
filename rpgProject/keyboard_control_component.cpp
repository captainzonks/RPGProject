#include "keyboard_control_component.h"

void keyboard_control_component::initialize()
{
	transform = owner->get_component<transform_component>();
	sprite = owner->get_component<sprite_component>();
}

void keyboard_control_component::update(float delta_time)
{
	if (game::event.type == SDL_KEYDOWN)
	{
		const auto key_code = std::to_string(game::event.key.keysym.sym);
		if (key_code == up_key)
		{
			transform->velocity.y = -40;
			transform->velocity.x = 0;
			sprite->play("up_animation");
		}
		if (key_code == right_key)
		{
			transform->velocity.y = 0;
			transform->velocity.x = 40;
			sprite->play("right_animation");
		}
		if (key_code == down_key)
		{
			transform->velocity.y = 40;
			transform->velocity.x = 0;
			sprite->play("down_animation");
		}
		if (key_code == left_key)
		{
			transform->velocity.y = 0;
			transform->velocity.x = -40;
			sprite->play("left_animation");
		}
		if (key_code == interact_key)
		{
			// TODO: handle interactions
		}
	}

	if (game::event.type == SDL_KEYUP)
	{
		const auto key_code = std::to_string(game::event.key.keysym.sym);
		if (key_code == up_key)
		{
			transform->velocity.y = 0;
		}
		if (key_code == right_key)
		{
			transform->velocity.x = 0;
		}
		if (key_code == down_key)
		{
			transform->velocity.y = 0;
		}
		if (key_code == left_key)
		{
			transform->velocity.x = 0;
		}
	}
}
