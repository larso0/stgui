/*
 * Widget.h
 *
 *  Created on: 6. sep. 2015
 *      Author: larso
 */

#ifndef SRC_WIDGET_H_
#define SRC_WIDGET_H_

#include <SDL2/SDL.h>
#include <vector>

namespace gui
{

class Widget
{
public:
    explicit Widget(Widget* parent, bool canDestroy);
    virtual ~Widget();

    virtual void resize(SDL_Rect* newSize) = 0;
    virtual void event(SDL_Event* event) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;

    virtual void addWidget(Widget* widget);
    virtual void removeWidget(Widget* toRemove);

    virtual void setBGColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    virtual void setFGColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    virtual void setPadding(int l, int r, int u, int d);
    virtual void setMargin(int l, int r, int u, int d);

    const SDL_Rect* getRectangle();
    void initialize(SDL_Rect* initSize);
    void resizeCallback();
protected:
    Widget* parent;
    std::vector<Widget*> children;

    SDL_Rect rect;
    SDL_Color bg, fg;
    struct { int l,r,u,d; } padding;
    struct { int l,r,u,d; } margin;

    bool canDestroy;
    bool show;

private:
    bool initialized;
    void setInit();
};

} /* namespace gui */

#endif /* SRC_WIDGET_H_ */
