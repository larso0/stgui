/*
 * main.cpp
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#include <SDL2/SDL.h>
#include <stdexcept>

#include "src/Window.h"

using namespace gui;

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        throw std::runtime_error("Could not initialize SDL.");
    }

    Window window;
    window.open();

    SDL_Event event;
    while(window.isOpen())
    {
        window.frame();
        while(SDL_PollEvent(&event))
        {
            window.event(&event);
        }
    }

    SDL_Quit();
    return 0;
}
