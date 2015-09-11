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
    padding = { 0,0,0,0 };
    margin = { 5,5,5,5 };
    initialized = false;
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

void Widget::setPadding(int l, int r, int u, int d)
{
    padding = { l,r,u,d };
    resizeCallback();
}

void Widget::setMargin(int l, int r, int u, int d)
{
    margin = { l,r,u,d };
    resizeCallback();
}

const SDL_Rect* gui::Widget::getRectangle()
{
    return &rect;
}

void Widget::initialize(SDL_Rect* initSize)
{
    setInit();
    resize(initSize);
}

void Widget::setInit()
{
    initialized = true;
    for(unsigned i = 0; i < children.size(); i++)
    {
        children[i]->setInit();
    }
}

void Widget::resizeCallback()
{
    if(initialized)
    {
        if(parent != nullptr) parent->resizeCallback();
        else resize(&rect);
    }
}

} /* namespace gui */
