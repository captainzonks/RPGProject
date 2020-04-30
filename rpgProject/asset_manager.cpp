#include "asset_manager.h"


#include "font_manager.h"
#include "texture_manager.h"

asset_manager asset_manager::asset_manager_instance_;

void asset_manager::clear_data()
{
	textures_.clear();
	fonts_.clear();
}

void asset_manager::add_texture(const std::string& texture_id, const char* file_path)
{
	textures_.try_emplace(texture_id, texture_manager::load_texture(file_path));
}

void asset_manager::add_font(const std::string& font_id, const char* file_path, const int font_size)
{
	fonts_.try_emplace(font_id, font_manager::load_font(file_path, font_size));
}

SDL_Texture* asset_manager::get_texture(const std::string& texture_id)
{
	return textures_[texture_id];
}

TTF_Font* asset_manager::get_font(const std::string& font_id)
{
	return fonts_[font_id];
}

