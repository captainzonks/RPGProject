#ifndef PROJECTILE_EMITTER_COMPONENT_H
#define PROJECTILE_EMITTER_COMPONENT_H

#include "component.h"
#include "transform_component.h"

class projectile_emitter_component :
	public component
{
public:
	projectile_emitter_component(int speed, float angle_deg, int range, bool should_loop);

	void initialize() override;

	void update(float delta_time) override;

private:

	transform_component* transform_ { nullptr };
	glm::vec2 origin_ {};
	int speed_ {};
	int range_ {};
	float angle_rad_ {};
	bool should_loop_ {};
};

#endif