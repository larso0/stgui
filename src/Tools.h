/*
 * Tools.h
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#ifndef SRC_TOOLS_H_
#define SRC_TOOLS_H_

#include <SDL2/SDL.h>
#include <stdexcept>

bool PointIsInsideRect(const SDL_Point* point, const SDL_Rect* rect);

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

#endif /* SRC_TOOLS_H_ */
