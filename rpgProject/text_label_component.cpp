#include "text_label_component.h"

#include <SDL_ttf.h>

#include "asset_manager.h"
#include "font_manager.h"
#include "game.h"

text_label_component::text_label_component(const int x, const int y, const std::string& text, const std::string& font_family,
                                           const SDL_Color& color)
{
	this->position_.x = x;
	this->position_.y = y;
	this->text_ = text;
	this->font_family_ = font_family;
	this->color_ = color;

	set_label_text(text, font_family);
}

void text_label_component::set_label_text(const std::string& text, const std::string& font_family)
{
	auto* surface = TTF_RenderText_Blended(asset_manager::instance()->get_font(font_family), text.c_str(), color_);
	texture_ = SDL_CreateTextureFromSurface(game::renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture_, nullptr, nullptr, &position_.w, &position_.h);
}

void text_label_component::render()
{
	font_manager::draw(texture_, position_);
}
