/*
 * HLayout.h
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#ifndef SRC_HLAYOUT_H_
#define SRC_HLAYOUT_H_

#include "Layout.h"

namespace gui
{

class HLayout : public Layout
{
public:
    HLayout(Widget* parent = nullptr, bool canDestroy = true);
    void resize(SDL_Rect* newSize);
};

} /* namespace gui */

#endif /* SRC_HLAYOUT_H_ */
