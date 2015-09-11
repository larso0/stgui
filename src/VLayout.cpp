/*
 * VLayout.cpp
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#include "VLayout.h"
#include <stdexcept>

namespace gui
{

VLayout::VLayout(Widget* parent, bool canDestroy)
: Layout(parent, canDestroy)
{
    bg.a = 0;
}

void VLayout::resize(SDL_Rect* newSize)
{
    if(newSize == nullptr) throw std::invalid_argument("New size is null pointer.");
    rect = *newSize;
    if(children.size() == 0) return;
    int height = 0;
    int lsize = rect.h - padding.u - padding.d - margin.u - margin.d;
    int wsize = lsize/children.size();
    int wcount = children.size();
    SDL_Rect wrect = rect;
    wrect.x += padding.l + margin.l;
    wrect.y += padding.u + margin.u;
    wrect.h = wsize;
    for(unsigned i = 0; i < children.size(); i++)
    {
        children[i]->resize(&wrect);
        wrect = *children[i]->getRectangle();
        height += wrect.h;
        lsize -= wrect.h;
        wcount--;
        if(wrect.h != wsize && lsize > 0 && wcount > 0)
        {
            wsize = lsize / wcount;
        }
        wrect.y += wrect.h;
        wrect.h = wsize;
        wrect.w = rect.w;
    }
    int delta = rect.h - padding.u - padding.d - margin.u - margin.d - height;
    if(delta > 0)
    {
        SDL_Rect tmp = *children.back()->getRectangle();
        tmp.h += delta;
        children.back()->resize(&tmp);
    }
    int width = 0;
    for(unsigned i = 0; i < children.size(); i++)
    {
        const SDL_Rect* crect = children[i]->getRectangle();
        if(crect->w > width) width = crect->w;
    }
    rect.w = width + margin.l + margin.r + padding.l + padding.r;
}

} /* namespace gui */
