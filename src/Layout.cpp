/*
 * Layout.cpp
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#include "Layout.h"
#include "Tools.h"

namespace gui
{

Layout::Layout(Widget* parent, bool canDestroy)
: Widget(parent, canDestroy)
{
    active = nullptr;
}

Layout::~Layout()
{
}

void Layout::event(SDL_Event* event)
{
    if(event == nullptr) return;
    if(event->type == SDL_MOUSEBUTTONUP && event->button.button == SDL_BUTTON_LEFT)
    {
        SDL_Point mpos = { event->button.x, event->button.y };
        for(unsigned i = 0; i < children.size(); i++)
        {
            if(PointIsInsideRect(&mpos, children[i]->getRectangle()))
            {
                active = children[i];
                break;
            }
        }
    }
    if(event->type == SDL_MOUSEMOTION)
    {
        for(unsigned i = 0; i < children.size(); i++)
        {
            children[i]->event(event);
        }
    }
    else if(active != nullptr) active->event(event);
}

void Layout::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
    SDL_RenderFillRect(renderer, &rect);
    for(unsigned i = 0; i < children.size(); i++)
    {
        children[i]->render(renderer);
    }
}

void Layout::addWidget(Widget* widget)
{
    Widget::addWidget(widget);
    if(active == nullptr && children.size() > 0)
    {
        active = children[0];
    }
}

} /* namespace gui */
