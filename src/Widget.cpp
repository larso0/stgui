/*
 * Widget.cpp
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#include "Widget.h"
#include <algorithm>

namespace gui
{

Widget::Widget(Widget* parent, bool canDestroy)
{
    this->parent = parent;
    if(parent != nullptr) parent->addWidget(this);
    this->canDestroy = canDestroy;
    show = true;
    bg = { 255, 255, 255, 255 };
    fg = { 0, 0, 0, 255 };
}

Widget::~Widget()
{
    for(auto iter = children.begin(); iter != children.end(); iter++)
    {
        if((*iter)->canDestroy) delete *iter;
    }
}

void Widget::addWidget(Widget* widget)
{
    if(widget != nullptr)
    {
        children.push_back(widget);
    }
}

void Widget::removeWidget(Widget* toRemove)
{
    std::remove(children.begin(), children.end(), toRemove);
}

void Widget::setBGColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    bg = { r, g, b, a };
}

void Widget::setFGColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    fg = { r, g, b, a };
}

const SDL_Rect* gui::Widget::getRectangle()
{
    return &rect;
}

void Widget::resizeCallback()
{
    resize(&rect);
}

} /* namespace gui */
