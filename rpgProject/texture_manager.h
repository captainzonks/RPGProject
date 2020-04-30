#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <SDL.h>

class texture_manager
{
public:
	static SDL_Texture* load_texture(const char* file_name);
	static void draw(SDL_Texture* texture, SDL_Rect source_rectangle, SDL_Rect destination_rectangle, SDL_RendererFlip flip);
	
};

#endif