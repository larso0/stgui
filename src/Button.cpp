/*
 * Button.cpp
 *
 *  Created on: 9. sep. 2015
 *      Author: larso
 */

#include "Button.h"
#include <stdexcept>
#include "Tools.h"

namespace gui
{

Button::Button(Widget* parent, bool canDestroy, TTF_Font* font)
: Widget(parent, canDestroy)
{
    text = new Label(this, true, font);
    state = NORMAL;
    fgHover = { 255, 255, 255, 255 };
    bgHover = { 0, 0, 127, 255 };
    fgClick = { 127, 127, 127, 255 };
    bgClick = { 0, 0, 64, 255 };
    text->setBGColor(0, 0, 0, 0);
    setBGColor(191, 191, 191, 255);
}

Button::~Button()
{
}

void Button::resize(SDL_Rect* newSize)
{
    if(newSize == nullptr) throw std::invalid_argument("Size rectangle was a nullpointer.");
    SDL_Rect tmp = *newSize;
    tmp.x += margin.l + padding.l;
    tmp.y += margin.u + padding.u;
    tmp.w -= padding.l + padding.r;
    tmp.h -= padding.u + padding.d;
    text->resize(&tmp);
    tmp = *text->getRectangle();
    rect = {
        newSize->x, newSize->y,
        tmp.w + margin.l + margin.r + padding.l + padding.r,
        tmp.h + margin.u + margin.d + padding.u + padding.d
    };
}

void Button::event(SDL_Event* event)
{
    SDL_Point pos;
    switch(event->type)
    {
    case SDL_MOUSEMOTION:
        pos.x = event->motion.x;
        pos.y = event->motion.y;
        if(PointIsInsideRect(&pos, &rect))
        {
            setState(HOVER);
        }
        else
        {
            setState(NORMAL);
        }
        break;
    case SDL_MOUSEBUTTONDOWN:
        pos.x = event->motion.x;
        pos.y = event->motion.y;
        if(PointIsInsideRect(&pos, &rect))
        {
            setState(CLICK);
        }
        break;
    case SDL_MOUSEBUTTONUP:
        pos.x = event->motion.x;
        pos.y = event->motion.y;
        if(PointIsInsideRect(&pos, &rect))
        {
            setState(HOVER);
            for(unsigned i = 0; i < callbacks.size(); i++)
            {
                callbacks[i]();
            }
        }
        break;
    default:
        break;
    }
}

void Button::render(SDL_Renderer* renderer)
{
    if(renderer == nullptr) throw std::invalid_argument("Renderer was a nullpointer.");
    switch(state)
    {
    case NORMAL:
        SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
        break;
    case HOVER:
        SDL_SetRenderDrawColor(renderer, bgHover.r, bgHover.g, bgHover.b, bgHover.a);
        break;
    case CLICK:
        SDL_SetRenderDrawColor(renderer, bgClick.r, bgClick.g, bgClick.b, bgClick.a);
        break;
    }
    SDL_Rect dst = rect;
    dst.x += margin.l + padding.l;
    dst.y += margin.u + padding.u;
    dst.w -= margin.l + margin.r + padding.l + padding.r;
    dst.h -= margin.u + margin.d + padding.u + padding.d;
    SDL_RenderFillRect(renderer, &dst);
    text->render(renderer);
}

void Button::setText(std::string text)
{
    this->text->setText(text);
}

void Button::onClick(std::function<void()> f)
{
    callbacks.push_back(f);
}

void Button::setState(State state)
{
    if(state != this->state)
    {
        this->state = state;
        switch(state)
        {
        case NORMAL:
            text->setFGColor(fg.r, fg.g, fg.b, fg.a);
            break;
        case HOVER:
            text->setFGColor(fgHover.r, fgHover.g, fgHover.b, fgHover.a);
            break;
        case CLICK:
            text->setFGColor(fgClick.r, fgClick.g, fgClick.b, fgClick.a);
            break;
        }
    }
}

} /* namespace gui */
