#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

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
	void update_sprite_direction() const;
	[[nodiscard]] bool is_moving() const { return velocity.x != 0 || velocity.y != 0; }
	glm::vec2 calculate_new_position(glm::vec2 current_target);

	void move(glm::vec2 direction);
	void finish_move(float delta_time);

	template <class T>
	typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
		almost_equal( T x, T y, int ulp )
	{
		return std::fabs(x - y) <= std::numeric_limits<T>::epsilon() * std::fabs(x + y) * ulp
			|| std::fabs(x - y) < std::numeric_limits<T>::min();
	}
};

#endif