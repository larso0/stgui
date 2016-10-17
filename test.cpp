/*
 * main.cpp
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdexcept>

#include "src/Window.h"
#include "src/Rectangle.h"
#include "src/VLayout.h"
#include "src/HLayout.h"
#include "src/Label.h"
#include "src/Button.h"
#include <string>

using namespace gui;

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        throw std::runtime_error("Could not initialize SDL.");
    }
    if(TTF_Init() != 0)
    {
        SDL_Quit();
        throw std::runtime_error("Could not initialize SDL TTF.");
    }
    TTF_Font* font = TTF_OpenFont("freefont/FreeSans.ttf", 18);
    if(font == nullptr)
    {
        TTF_Quit();
        SDL_Quit();
        throw std::runtime_error("Could not open font.");
    }

    Window window;

    VLayout layout;

    HLayout hl1(&layout, false);
    Label lbl1(&hl1, false, font);
    Button btn1(&hl1, false, font);
    Button rst1(&hl1, false, font);
    unsigned long counter = 0;
    lbl1.setText(std::to_string(counter));
    btn1.setText("Count");
    btn1.onClick([&counter, &lbl1]{
        counter++;
        lbl1.setText(std::to_string(counter));
    });
    rst1.setText("Reset");
    rst1.onClick([&counter, &lbl1]{
        counter = 0;
        lbl1.setText(std::to_string(counter));
    });

    HLayout hl2(&layout, false);
    Label lbl2(&hl2, false, font);
    Button btn2(&hl2, false, font);
    Button rst2(&hl2, false, font);
    unsigned long long dbl = 1;
    lbl2.setText(std::to_string(dbl));
    btn2.setText("Double");
    btn2.onClick([&dbl, &lbl2]{
        dbl = dbl + dbl;
        lbl2.setText(std::to_string(dbl));
    });
    rst2.setText("Reset");
    rst2.onClick([&dbl, &lbl2]{
        dbl = 1;
        lbl2.setText(std::to_string(dbl));
    });

    window.setWidget(&layout);
    window.open();

    SDL_Event event;
    while(window.isOpen() && SDL_WaitEvent(&event))
    {
        window.event(&event);
        while(SDL_PollEvent(&event)) window.event(&event);
        if(window.isOpen()) window.render();
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
    return 0;
}
