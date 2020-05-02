#include "projectile_emitter_component.h"

#include "entity.h"

projectile_emitter_component::projectile_emitter_component(int speed, float angle_deg, int range, bool should_loop)
{
	this->speed_ = speed;
	this->angle_rad_ = glm::radians(static_cast<float>(angle_deg));
	this->range_ = range;
	this->should_loop_ = should_loop;
}

void projectile_emitter_component::initialize()
{
	transform_ = owner->get_component<transform_component>();
	origin_ = glm::vec2(transform_->position.x, transform_->position.y);
	transform_->velocity = glm::vec2(glm::cos(angle_rad_) * speed_, glm::sin(angle_rad_) * speed_);
}

void projectile_emitter_component::update(float delta_time)
{
	if (glm::distance(transform_->position, origin_) > range_)
	{
		if (should_loop_)
		{
			transform_->position.x = origin_.x;
			transform_->position.y = origin_.y;
		}
		else
		{
			owner->destroy();
		}
	}
}
