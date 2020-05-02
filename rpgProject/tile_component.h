#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include <SDL.h>
#include <string>


#include "component.h"
#include "lib/glm/vec2.hpp"

class tile_component :
	public component
{
public:
	SDL_Texture* texture { nullptr };
	SDL_Rect source_rectangle;
	SDL_Rect destination_rectangle;
	glm::vec2 position;

	tile_component(int source_rect_x, int source_rect_y, int x, int y, int tile_size, int tile_scale, const std::string& asset_texture_id);

	~tile_component() { SDL_DestroyTexture(texture); }

	void update(float delta_time) override;
	void render() override;
	
};

#endif