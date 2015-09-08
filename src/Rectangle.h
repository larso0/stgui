/*
 * Rectangle.h
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#ifndef SRC_RECTANGLE_H_
#define SRC_RECTANGLE_H_

#include "Widget.h"

namespace gui
{

class Rectangle : public Widget
{
public:
    Rectangle(Widget* parent = nullptr, bool canDestroy = true);
    ~Rectangle();

    void resize(SDL_Rect* newSize);
    void event(SDL_Event* event);
    void render(SDL_Renderer* renderer);
};

} /* namespace gui */

#endif /* SRC_RECTANGLE_H_ */
