/*
 * main.cpp
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#include <SDL2/SDL.h>
#include <stdexcept>

#include "src/Window.h"
#include "src/Rectangle.h"
#include "src/VLayout.h"
#include "src/HLayout.h"

using namespace gui;

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        throw std::runtime_error("Could not initialize SDL.");
    }

    Window window;

    HLayout layout;

    VLayout vlayout1(&layout, false);
    Rectangle red1(&vlayout1, false);
    red1.setFGColor(255, 0, 0, 255);
    Rectangle green1(&vlayout1, false);
    green1.setFGColor(0, 255, 0, 255);
    Rectangle blue1(&vlayout1, false);
    blue1.setFGColor(0, 0, 255, 255);

    VLayout vlayout2(&layout, false);
    Rectangle blue2(&vlayout2, false);
    blue2.setFGColor(0, 0, 255, 255);
    Rectangle red2(&vlayout2, false);
    red2.setFGColor(255, 0, 0, 255);
    Rectangle green2(&vlayout2, false);
    green2.setFGColor(0, 255, 0, 255);

    VLayout vlayout3(&layout, false);
    Rectangle green3(&vlayout3, false);
    green3.setFGColor(0, 255, 0, 255);
    Rectangle blue3(&vlayout3, false);
    blue3.setFGColor(0, 0, 255, 255);
    Rectangle red3(&vlayout3, false);
    red3.setFGColor(255, 0, 0, 255);

    window.setWidget(&layout);
    window.open();

    SDL_Event event;
    while(window.isOpen())
    {
        window.render();
        while(SDL_PollEvent(&event))
        {
            window.event(&event);
        }
    }

    SDL_Quit();
    return 0;
}
