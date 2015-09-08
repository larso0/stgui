/*
 * Label.cpp
 *
 *  Created on: 8. sep. 2015
 *      Author: larso
 */

#include "Label.h"
#include <stdexcept>

namespace gui
{

Label::Label(Widget* parent, bool canDestroy, TTF_Font* font)
: Widget(parent, canDestroy)
{
    if(font == nullptr) throw std::invalid_argument("Font was a nullpointer.");
    this->font = font;
    tsurf = nullptr;
    ttex = nullptr;
}
Label::~Label()
{
    if(ttex != nullptr)
    {
        SDL_DestroyTexture(ttex);
        ttex = nullptr;
    }
    if(tsurf != nullptr)
    {
        SDL_FreeSurface(tsurf);
        tsurf = nullptr;
    }
}

void Label::resize(SDL_Rect* newSize)
{
    if(newSize == nullptr) throw std::invalid_argument("Size to resize to was nullptr");
    rect = *newSize;
    if(ttex != nullptr)
    {
        SDL_DestroyTexture(ttex);
        ttex = nullptr;
    }
    if(tsurf != nullptr)
    {
        SDL_FreeSurface(tsurf);
        tsurf = nullptr;
    }
    tsurf = TTF_RenderUTF8_Blended_Wrapped(font, text.c_str(), fg, newSize->w);
    if(tsurf == nullptr) throw std::runtime_error("Could not render label text.");
    rect.h = tsurf->h;
    rect.w = tsurf->w;
}

void Label::event(SDL_Event* event)
{
}

void Label::render(SDL_Renderer* renderer)
{
    if(renderer == nullptr) throw std::invalid_argument("Renderer was a nullpointer.");
    if(ttex == nullptr)
    {
        if(tsurf == nullptr) throw std::runtime_error("Text is not rendered for label.");
        ttex = SDL_CreateTextureFromSurface(renderer, tsurf);
        if(ttex == nullptr) throw std::runtime_error("Could not create texture for label.");
    }
    SDL_SetRenderDrawColor(renderer, bg.r, bg.g, bg.b, bg.a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderCopy(renderer, ttex, nullptr, &rect);
}

void Label::setText(std::string text)
{
    this->text = text;
    if(ttex != nullptr)
    {
        SDL_DestroyTexture(ttex);
        ttex = nullptr;
    }
    if(tsurf != nullptr)
    {
        SDL_FreeSurface(tsurf);
        tsurf = nullptr;
    }
}

} /* namespace gui */
