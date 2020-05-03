#ifndef SPRITE_COMPONENT_H
#define SPRITE_COMPONENT_H

#include <map>
#include <SDL.h>
#include <string>

#include "animation.h"
#include "component.h"
#include "transform_component.h"

class sprite_component final
	:	public component
{
public:
	SDL_RendererFlip sprite_flip = SDL_FLIP_NONE;

	explicit sprite_component(const std::string& asset_texture_id);

	explicit sprite_component(const std::string& asset_texture_id, bool is_fixed);

	explicit sprite_component(const std::string& id, int num_frames, int animation_speed,
	                          bool has_directions, bool is_fixed);

	void play(const std::string& animation_name);

	void set_texture(const std::string& asset_texture_id);

	void initialize() override;

	void update(float delta_time) override;

	void render() override;

private:
	transform_component* transform_ {};
	SDL_Texture* texture_ {};
	SDL_Rect source_rectangle_ {};
	SDL_Rect destination_rectangle_ {};
	bool is_animated_ {};
	int num_frames_ {};
	int animation_speed_ {};
	bool is_fixed_ {};
	std::map<std::string, animation> animations_ {};
	std::string current_animation_name_ {};
	unsigned animation_index_ {};
	
};

#endif