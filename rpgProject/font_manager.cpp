#include "font_manager.h"

#include "game.h"

TTF_Font* font_manager::load_font(const char* file_name, const int font_size)
{
	return TTF_OpenFont(file_name, font_size);
}

void font_manager::draw(SDL_Texture* texture, SDL_Rect position)
{
	SDL_RenderCopy(game::renderer, texture, nullptr, &position);
}
