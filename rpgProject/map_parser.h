#ifndef MAP_PARSER_H
#define MAP_PARSER_H

#include <map>
#include <string>

#include "game_map.h"
#include "tile_layer.h"
#include "./assets/tinyxml/tinyxml.h"

class map_parser
{
public:

	bool load();
	void clean_up();

	game_map* get_maps();
	
	static map_parser* instance() { return &map_parser_instance_; }

protected:
	map_parser() = default;
	static map_parser map_parser_instance_;

private:

	bool parse(std::string map_id, std::string source);
	tileset parse_tile_set(TiXmlElement* xml_tile_set);
	tile_layer* parse_tile_layer(TiXmlElement* xml_layer, tile_set_list tile_sets, int tile_size, int row_count, int column_count);
	
	std::map<std::string, game_map*> game_maps_;
};

#endif