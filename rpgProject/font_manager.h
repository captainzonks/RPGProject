#ifndef FONT_MANAGER_H
#define FONT_MANAGER_H
#include <SDL_ttf.h>

class font_manager
{
public:
	static TTF_Font* load_font(const char* file_name, int font_size);
	static void draw(SDL_Texture* texture, SDL_Rect position);
};

#endif