/*
 * Label.h
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#ifndef SRC_LABEL_H_
#define SRC_LABEL_H_

#include "Widget.h"
#include <SDL2/SDL_ttf.h>
#include <string>

namespace gui
{

class Label : public Widget
{
public:
    Label(Widget* parent, bool canDestroy, TTF_Font* font);
    ~Label();
    void resize(SDL_Rect* newSize);
    void event(SDL_Event* event);
    void render(SDL_Renderer* renderer);

    void setText(std::string text);
private:
    std::string text;
    TTF_Font* font;
    SDL_Surface* tsurf;
    SDL_Texture* ttex;
};

} /* namespace gui */

#endif /* SRC_LABEL_H_ */
