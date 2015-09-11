/*
 * Rectangle.cpp
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#include "Rectangle.h"
#include <stdexcept>

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
    if(newSize == nullptr) throw std::invalid_argument("Size to resize to was nullptr");
    rect = *newSize;
    rect.w += margin.l + margin.r;
    rect.h += margin.u + margin.d;
}

void Rectangle::event(SDL_Event* event)
{
}

void Rectangle::render(SDL_Renderer* renderer)
{
    SDL_Rect dst = rect;
    dst.x += margin.l + padding.l;
    dst.y += margin.u + padding.u;
    dst.w -= margin.l + margin.r + padding.l + padding.r;
    dst.h -= margin.u + margin.d + padding.u + padding.d;
    SDL_SetRenderDrawColor(renderer, fg.r, fg.g, fg.b, fg.a);
    SDL_RenderFillRect(renderer, &dst);
}

} /* namespace gui */
