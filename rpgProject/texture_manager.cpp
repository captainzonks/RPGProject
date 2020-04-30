#include "texture_manager.h"

#include <SDL_image.h>

#include "game.h"

SDL_Texture* texture_manager::load_texture(const char* file_name)
{
	const auto surface = IMG_Load(file_name);
	const auto texture = SDL_CreateTextureFromSurface(game::renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void texture_manager::draw(SDL_Texture* texture, SDL_Rect source_rectangle, SDL_Rect destination_rectangle, const SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(game::renderer, texture, &source_rectangle, &destination_rectangle, 0.0, nullptr, flip);
}
