/*
 * Button.h
 *
 *  Created on: 9. sep. 2015
 *      Author: larso
 */

#ifndef SRC_BUTTON_H_
#define SRC_BUTTON_H_

#include "Widget.h"
#include "Label.h"
#include <functional>

namespace gui
{

class Button : public Widget
{
public:
    Button(Widget* parent, bool canDestroy, TTF_Font* font);
    ~Button();

    void resize(SDL_Rect* newSize);
    void event(SDL_Event* event);
    void render(SDL_Renderer* renderer);
    void setText(std::string text);
    void onClick(std::function<void()> f);
private:
    enum State { NORMAL, HOVER, CLICK };
    SDL_Color fgHover, bgHover;
    SDL_Color fgClick, bgClick;
    State state;
    std::vector<std::function<void()>> callbacks;
    Label* text;

    void setState(State state);
};

} /* namespace gui */

#endif /* SRC_BUTTON_H_ */
