#include "map_parser.h"

map_parser map_parser::map_parser_instance_;

bool map_parser::load()
{
	return parse("level1", "./assets/maps/map_01.tmx");
}

void map_parser::clean_up()
{
	
}

game_map* map_parser::get_maps()
{
	
}

bool map_parser::parse(std::string map_id, std::string source)
{
}

tileset map_parser::parse_tile_set(TiXmlElement* xml_tile_set)
{
	tileset tile_set;
	tile_set.name = xml_tile_set->Attribute("name");
	xml_tile_set->Attribute("firstgid", &tile_set.first_id);

	xml_tile_set->Attribute("tilecount", &tile_set.tile_count);
	tile_set.last_id = (tile_set.first_id + tile_set.tile_count) - 1;

	xml_tile_set->Attribute("columns", &tile_set.column_count);
	tile_set.row_count = tile_set.tile_count / tile_set.column_count;
	xml_tile_set->Attribute("tilewidth", &tile_set.tile_size);

	auto* image = xml_tile_set->FirstChildElement();
	tile_set.source = image->Attribute("source");
	return tile_set;
}

tile_layer* map_parser::parse_tile_layer(TiXmlElement* xml_layer, tile_set_list tile_sets, int tile_size, int row_count,
	int column_count)
{
}



