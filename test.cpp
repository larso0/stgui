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

using namespace gui;

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        throw std::runtime_error("Could not initialize SDL.");
    }

    Window window;

    VLayout layout;

    Rectangle red(&layout, false);
    red.setFGColor(255, 0, 0, 255);

    Rectangle green(&layout, false);
    green.setFGColor(0, 255, 0, 255);

    Rectangle blue(&layout, false);
    blue.setFGColor(0, 0, 255, 255);

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
