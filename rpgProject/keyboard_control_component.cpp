#include "keyboard_control_component.h"

#include "game.h"
#include "entity.h"

keyboard_control_component::keyboard_control_component(std::string up_key, std::string right_key, std::string down_key,
	std::string left_key, std::string interact_key)
{
	this->up_key = get_sdl_key_string_code(std::move(up_key));
	this->right_key = get_sdl_key_string_code(std::move(right_key));
	this->down_key = get_sdl_key_string_code(std::move(down_key));
	this->left_key = get_sdl_key_string_code(std::move(left_key));
	this->interact_key = get_sdl_key_string_code(std::move(interact_key));
}

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

std::string keyboard_control_component::get_sdl_key_string_code(std::string key) const
{
	if (key == "up")
		return "1073741906";
	if (key == "right")
		return "1073741903";
	if (key == "down")
		return "1073741905";
	if (key == "left")
		return "1073741904";
	if (key == "space")
		return "32";
	return std::to_string(static_cast<int>(key[0]));
}