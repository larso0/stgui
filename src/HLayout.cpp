/*
 * HLayout.cpp
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#include "HLayout.h"
#include <stdexcept>

namespace gui
{

HLayout::HLayout(Widget* parent, bool canDestroy)
: Layout(parent, canDestroy)
{
}

void HLayout::resize(SDL_Rect* newSize)
{
    if(newSize == nullptr) throw std::invalid_argument("New size is null pointer.");
    rect = *newSize;
    if(children.size() == 0) return;
    int width = 0, lsize = rect.w, wsize = lsize/children.size();
    int wcount = children.size();
    SDL_Rect wrect = rect;
    wrect.w = wsize;
    for(unsigned i = 0; i < children.size(); i++)
    {
        children[i]->resize(&wrect);
        wrect = *children[i]->getRectangle();
        width += wrect.w;
        lsize -= wrect.w;
        wcount--;
        if(wrect.w != wsize && lsize > 0 && wcount > 0)
        {
            wsize = lsize / wcount;
        }
        wrect.x += wrect.w;
        wrect.w = wsize;
        wrect.h = rect.h;
    }
    int delta = newSize->w - width;
    if(delta > 0)
    {
        SDL_Rect tmp = *children.back()->getRectangle();
        tmp.w += delta;
        children.back()->resize(&tmp);
    }
}

} /* namespace gui */
