#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <algorithm>
#include <iostream>

#include "component.h"

#include "./lib/glm/glm.hpp"
#include "constants.h"

class transform_component final
	: public component
{
public:
	glm::vec2 position{};
	glm::vec2 target_position{ 0, 0};
	glm::vec2 velocity{ 0, 0 };
	direction facing{ direction::down };
	int width{};
	int height{};
	int scale{};

	transform_component(int pos_x, int pos_y, int vel_x, int vel_y, int w, int h,
	                    int s);

	~transform_component();

	void initialize() override {}

	void update(float delta_time) override;

	void render() override {}

	void update_direction();
	[[nodiscard]] bool is_moving() const { return is_moving_; }

	void move(glm::vec2 direction);

private:
	bool is_moving_ { false };
	int move_time_ {};
	int frames_to_cross_one_tile_ { 32 };
};

#endif