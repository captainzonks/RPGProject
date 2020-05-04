#include "game_map.h"

#include <fstream>

#include "entity_manager.h"
#include "entity.h"
#include "game.h"
#include "tile_component.h"

void game_map::render()
{
	for (auto& layer : map_layers_)
		layer->render();
}

void game_map::update(float delta_time)
{
	for (auto& layer : map_layers_)
		layer->update();
}

void game_map::load_map(const std::string& file_path, const int map_size_x, const int map_size_y)
{
	std::fstream map_file;
	map_file.open(file_path);

	for (int y {}; y < map_size_y; y++)
	{
		for (int x {}; x < map_size_x; x++)
		{
			char ch;
			map_file.get(ch);
			const auto source_rect_y = atoi(&ch) * tile_size_;
			map_file.get(ch);
			const auto source_rect_x = atoi(&ch) * tile_size_;
			add_tile(source_rect_x, source_rect_y, x * (scale_ * tile_size_), y * (scale_ * tile_size_));
			map_file.ignore();
		}
	}
	map_file.close();
}

void game_map::add_tile(int source_x, int source_y, int x, int y)
{
	auto& new_tile(entity_manager::instance()->add_entity("Tile", layer_type::tile_map_layer));
	new_tile.add_component<tile_component>(source_x, source_y, x, y, tile_size_, scale_, texture_id_);
}
