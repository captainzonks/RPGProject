#include "sprite_component.h"

#include "asset_manager.h"
#include "entity.h"
#include "game.h"
#include "texture_manager.h"

sprite_component::sprite_component(const std::string& asset_texture_id)
{
	this->is_animated_ = false;
	this->is_fixed_ = false;
	set_texture(asset_texture_id);
}

sprite_component::sprite_component(const std::string& asset_texture_id, const bool is_fixed)
{
	this->is_animated_ = false;
	this->is_fixed_ = is_fixed;
	set_texture(asset_texture_id);
}

sprite_component::sprite_component(const std::string& id, const int num_frames, const int animation_speed,
                                   const bool has_directions, const bool is_fixed)
{
	this->is_animated_ = true;
	this->num_frames_ = num_frames;
	this->animation_speed_ = animation_speed;
	this->is_fixed_ = is_fixed;

	if (has_directions)
	{
		auto down_animation = animation(0, num_frames, animation_speed);
		auto right_animation = animation(1, num_frames, animation_speed);
		auto left_animation = animation(2, num_frames, animation_speed);
		auto up_animation = animation(3, num_frames, animation_speed);
		animations_.emplace("down_animation", down_animation);
		animations_.emplace("right_animation", right_animation);
		animations_.emplace("left_animation", left_animation);
		animations_.emplace("up_animation", up_animation);
		this->animation_index_ = 0;
		this->current_animation_name_ = "down_animation";
	}
	else
	{
		auto single_animation = animation(0, num_frames, animation_speed);
		animations_.emplace("single_animation", single_animation);
		this->animation_index_ = 0;
		this->current_animation_name_ = "single_animation";
	}

	play(this->current_animation_name_);

	set_texture(id);
}

void sprite_component::play(const std::string& animation_name)
{
	num_frames_ = animations_[animation_name].num_frames;
	animation_index_ = animations_[animation_name].index;
	animation_speed_ = animations_[animation_name].animation_speed;
	current_animation_name_ = animation_name;
}

void sprite_component::set_texture(const std::string& asset_texture_id)
{
	texture_ = asset_manager::instance()->get_texture(asset_texture_id);
}

void sprite_component::initialize()
{
	transform_ = owner->get_component<transform_component>();
	source_rectangle_.x = 0;
	source_rectangle_.y = 0;
	source_rectangle_.w = transform_->width;
	source_rectangle_.h = transform_->height;
}

void sprite_component::update(float delta_time)
{
	if (is_animated_)
	{
		source_rectangle_.x = source_rectangle_.w * static_cast<int>( SDL_GetTicks() / animation_speed_ % num_frames_ );
	}
	source_rectangle_.y = static_cast<int>(animation_index_) * transform_->height;

	destination_rectangle_.x = static_cast<int>(transform_->position.x) - ( is_fixed_ ? 0 : game::camera.x );
	destination_rectangle_.y = static_cast<int>(transform_->position.y) - ( is_fixed_ ? 0 : game::camera.y );
	destination_rectangle_.w = transform_->width * transform_->scale;
	destination_rectangle_.h = transform_->height * transform_->scale;
}

void sprite_component::render()
{
	texture_manager::draw(texture_, source_rectangle_, destination_rectangle_, sprite_flip);
}
