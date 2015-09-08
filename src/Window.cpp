/*
 * Window.cpp
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#include "Window.h"
#include <stdexcept>

namespace gui
{

Window::Window()
{
    w = 640;
    h = 480;
    isopen = false;
    win = nullptr;
    wID = 0;
    ren = nullptr;
    wflags = SDL_WINDOW_RESIZABLE;
    rflags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    rindex = -1;
    title = "Window";
    widget = nullptr;
}

Window::~Window()
{
    if(ren != nullptr) SDL_DestroyRenderer(ren);
    if(win != nullptr) SDL_DestroyWindow(win);
}

bool Window::isOpen()
{
    return isopen;
}

void Window::open()
{
    if(!isopen)
    {
        win = SDL_CreateWindow(title.c_str(),
                               SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               w, h, wflags);
        if(win == nullptr)
        {
            throw std::runtime_error(SDL_GetError());
        }

        ren = SDL_CreateRenderer(win, rindex, rflags);
        if(ren == nullptr)
        {
            std::string error(SDL_GetError());
            SDL_DestroyWindow(win);
            throw std::runtime_error(error);
        }

        isopen = true;
        wID = SDL_GetWindowID(win);
    }
}

void Window::close()
{
    if(isopen)
    {
        isopen = false;
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        ren = nullptr;
        win = nullptr;
    }
}

void Window::frame(std::function<void(SDL_Renderer*)> f)
{
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    f(ren);
    SDL_RenderPresent(ren);
}

void Window::event(SDL_Event* event)
{
    switch(event->type)
    {
    case SDL_QUIT:
        close();
        break;
    case SDL_WINDOWEVENT:
        if(event->window.windowID == wID)
        {
            switch(event->window.event)
            {
            case SDL_WINDOWEVENT_RESIZED:
                w = event->window.data1;
                h = event->window.data2;
                if(widget != nullptr)
                {
                    SDL_Rect nsize = { 0, 0, w, h };
                    widget->resize(&nsize);
                }
                break;
            default:
                break;
            }
        }
    }
    if(widget != nullptr)
    {
        widget->event(event);
    }
}

void Window::setSize(unsigned w, unsigned h)
{
    if(isopen)
    {
        SDL_SetWindowSize(win, w, h);
    }
    this->w = w;
    this->h = h;
}

void Window::setWindowFlags(Uint32 flags)
{
    wflags = flags;
}

void Window::setRendererIndex(int index)
{
    rindex = index;
}

void Window::setRendererFlags(Uint32 flags)
{
    rflags = flags;
}

unsigned Window::getWidth()
{
    return w;
}

void Window::setWidget(Widget* widget)
{
    this->widget = widget;
}

unsigned Window::getHeight()
{
    return h;
}

void Window::setTitle(std::string title)
{
    this->title = title;
    if(isopen)
    {
        SDL_SetWindowTitle(win, title.c_str());
    }
}

} /* namespace gui */
