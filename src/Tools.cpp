/*
 * Tools.cpp
 *
 *  Created on: 9. sep. 2015
 *      Author: larso
 */
#include "Tools.h"

bool PointIsInsideRect(const SDL_Point* point, const SDL_Rect* rect)
{
    if(point == nullptr || rect == nullptr)
    {
        throw std::invalid_argument("Argument was nullpointer.");
    }
    return point->x >= rect->x && point->y >= rect->y
            && point->x < rect->x + rect->w
            && point->y < rect->y + rect->h;
}
