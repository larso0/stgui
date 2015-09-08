/*
 * Layout.h
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#ifndef SRC_LAYOUT_H_
#define SRC_LAYOUT_H_

#include "Widget.h"

namespace gui
{

class Layout : public Widget
{
public:
    explicit Layout(Widget* parent, bool canDestroy = true);
    virtual ~Layout();

    virtual void resize(SDL_Rect* newSize) = 0;
    virtual void event(SDL_Event* event);
    virtual void render(SDL_Renderer* renderer);

    void addWidget(Widget* widget);

protected:
    Widget* active;
};

} /* namespace gui */

#endif /* SRC_LAYOUT_H_ */
