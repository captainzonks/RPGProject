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
	glm::vec2 calculate_new_position(glm::vec2 current_target);

	void move(glm::vec2 direction);
	void finish_move(float delta_time);

	template <typename T, typename T2>
	typename std::enable_if<!std::numeric_limits<T>::is_integer, int32_t>::type
		ulps_distance(const T a, const T2 b)
	{
		if (a == b)
			return 0;

		constexpr auto max = std::numeric_limits<int32_t>::max();

		// max distance for NaN
		if (isnan(a) || isnan(b))
			return max;
		// if one's infinite and they're not equal, max distance
		if (isinf(a) || isinf(b))
			return max;

		int32_t ia, ib;
		memcpy(&ia, &a, sizeof(T));
		memcpy(&ib, &b, sizeof(T2));

		// don't compare differently-signed
		if (ia < 0 != ib < 0)
			return max;

		// return the absolute value of the distance in ULPs
		auto distance = ia - ib;
		if (distance < 0)
			distance = -distance;

		return distance;
	}

	template <typename T>
	typename std::enable_if<!std::numeric_limits<T>::is_integer, int32_t>::type
		t_to_int(T x)
	{
		int32_t r;
		memcpy(&r, &x, sizeof(T));
		return r;
	}
	
	template <class T>
	typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
		almost_equal( T x, T y)
	{
		const T difference { std::fabs(x - y) };
		if (difference <= std::numeric_limits<T>::epsilon())
			return true;

		return ulps_distance(x, y) <= 100000;
	}

private:
	bool is_moving_ { false };
};

#endif