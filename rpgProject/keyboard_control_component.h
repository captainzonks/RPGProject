#ifndef KEYBOARD_CONTROL_COMPONENT_H
#define KEYBOARD_CONTROL_COMPONENT_H

#include <string>

#include "component.h"
#include "sprite_component.h"
#include "transform_component.h"

class keyboard_control_component final
	:	public component
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
	keyboard_control_component(std::string up_key, std::string right_key, std::string down_key, std::string left_key, std::string interact_key);

	void initialize() override;

	void update(float delta_time) override;

	[[nodiscard]] std::string get_sdl_key_string_code(std::string key) const;
};

#endif