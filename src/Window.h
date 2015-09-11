/*
 * Window.h
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#ifndef SRC_WINDOW_H_
#define SRC_WINDOW_H_

#include <SDL2/SDL.h>
#include <string>
#include <functional>
#include "Widget.h"

namespace gui
{

class Window
{
public:
    Window();
    ~Window();

    bool isOpen();
    void open();
    void close();

    void render();
    void event(SDL_Event* event);

    void setWindowFlags(Uint32 flags);
    void setRendererIndex(int index);
    void setRendererFlags(Uint32 flags);
    void setSize(unsigned w, unsigned h);
    void setTitle(std::string title);
    void setWidget(Widget* widget);

    unsigned getWidth();
    unsigned getHeight();
private:
    SDL_Window* win;
    Uint32 wID;
    Uint32 wflags;
    std::string title;
    SDL_Renderer* ren;
    Uint32 rflags;
    int rindex;

    bool isopen;
    int w, h;

    Widget* widget;
};

} /* namespace gui */

#endif /* SRC_WINDOW_H_ */
