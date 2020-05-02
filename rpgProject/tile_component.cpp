#include "tile_component.h"

#include "asset_manager.h"
#include "game.h"
#include "texture_manager.h"

tile_component::tile_component(const int source_rect_x, const int source_rect_y, const int x, const int y, const int tile_size, const int tile_scale,
                               const std::string& asset_texture_id)
{
	texture = asset_manager::instance()->get_texture(asset_texture_id);

	source_rectangle.x = source_rect_x;
	source_rectangle.y = source_rect_y;
	source_rectangle.w = tile_size;
	source_rectangle.h = tile_size;

	destination_rectangle.x = x;
	destination_rectangle.y = y;
	destination_rectangle.w = tile_size * tile_scale;
	destination_rectangle.h = tile_size * tile_scale;

	position.x = x;
	position.y = y;
}

void tile_component::update(float delta_time)
{
	destination_rectangle.x = position.x - game::camera.x;
	destination_rectangle.y = position.y - game::camera.y;
}

void tile_component::render()
{
	texture_manager::draw(texture, source_rectangle, destination_rectangle, SDL_FLIP_NONE);
}
