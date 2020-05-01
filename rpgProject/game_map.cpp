#include "game_map.h"

#include <fstream>

#include "entity_manager.h"

extern entity_manager manager;

void game_map::load_map(const std::string& file_path, const int map_size_x, const int map_size_y) const
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
		}
	}
}

void game_map::add_tile(int source_x, int source_y, int x, int y)
{
	auto& new_tile(entity_manager::instance()->add_entity("Tile", layer_type::tile_map_layer));
}
