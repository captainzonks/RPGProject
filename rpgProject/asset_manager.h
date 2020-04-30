#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H
#include <map>
#include <SDL.h>
#include <SDL_ttf.h>



#include "character_manager.h"

class asset_manager
{
public:
	~asset_manager() = default;
	void clear_data();

	void add_texture(const std::string& texture_id, const char* file_path);
	void add_font(const std::string& font_id, const char* file_path, int font_size);

	SDL_Texture* get_texture(const std::string& texture_id);
	TTF_Font* get_font(const std::string& font_id);

	static asset_manager* instance()
	{
		return &asset_manager_instance_;
	}
	
protected:
	asset_manager() = default;
	static asset_manager asset_manager_instance_;
	
private:
	std::map<std::string, SDL_Texture*> textures_;
	std::map<std::string, TTF_Font*> fonts_;
};

#endif