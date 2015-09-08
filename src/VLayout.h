/*
 * VLayout.h
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#ifndef SRC_VLAYOUT_H_
#define SRC_VLAYOUT_H_

#include "Layout.h"

namespace gui
{

class VLayout : public Layout
{
public:
    VLayout(Widget* parent = nullptr, bool canDestroy = true);
    void resize(SDL_Rect* newSize);
};

} /* namespace gui */

#endif /* SRC_VLAYOUT_H_ */
