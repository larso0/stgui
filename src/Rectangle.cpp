/*
 * Rectangle.cpp
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#include "Rectangle.h"

namespace gui
{

Rectangle::Rectangle(Widget* parent, bool canDestroy)
: Widget(parent, canDestroy)
{

}

Rectangle::~Rectangle()
{
}

void Rectangle::resize(SDL_Rect* newSize)
{
    rect = *newSize;
}

void Rectangle::event(SDL_Event* event)
{
}

void Rectangle::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, fg.r, fg.g, fg.b, fg.a);
    SDL_RenderFillRect(renderer, &rect);
}

} /* namespace gui */
