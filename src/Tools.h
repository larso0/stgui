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

#endif /* SRC_TOOLS_H_ */
