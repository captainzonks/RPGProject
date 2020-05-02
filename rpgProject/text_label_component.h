#ifndef TEXT_LABEL_COMPONENT_H
#define TEXT_LABEL_COMPONENT_H

#include <SDL.h>
#include <string>


#include "component.h"
class text_label_component :
	public component
{
public:
	text_label_component(int x, int y, const std::string& text, const std::string& font_family, const SDL_Color& color);

	void set_label_text(const std::string& text, const std::string& font_family);

	void render() override;
	
private:
	SDL_Rect position_;
	std::string text_;
	std::string font_family_;
	SDL_Color color_;
	SDL_Texture* texture_ { nullptr };
};

#endif