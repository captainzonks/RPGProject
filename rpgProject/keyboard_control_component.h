#ifndef KEYBOARD_CONTROL_COMPONENT_H
#define KEYBOARD_CONTROL_COMPONENT_H

#include <string>

#include "component.h"
#include "sprite_component.h"
#include "transform_component.h"
#include "entity.h"
#include "game.h"

class keyboard_control_component final :
	public component
{
public:
	std::string up_key;
	std::string right_key;
	std::string down_key;
	std::string left_key;
	std::string interact_key;

	transform_component* transform { nullptr };
	sprite_component* sprite { nullptr };

	keyboard_control_component() = default;
	keyboard_control_component(std::string up_key, std::string right_key, std::string down_key, std::string left_key, std::string interact_key)
		: up_key(std::move(up_key)), right_key(std::move(right_key)), down_key(std::move(down_key)), left_key(std::move(left_key)), interact_key(std::move(interact_key))
	{
	}

	void initialize() override;

	void update(float delta_time) override;
};

#endif