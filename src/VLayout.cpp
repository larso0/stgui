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
}

void VLayout::resize(SDL_Rect* newSize)
{
    if(newSize == nullptr) throw std::invalid_argument("New size is null pointer.");
    rect = *newSize;
    if(children.size() == 0) return;
    int height = 0, lsize = rect.h, wsize = rect.h/children.size();
    int wcount = children.size();
    SDL_Rect wrect = rect;
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
    rect.h = height;
}

} /* namespace gui */
