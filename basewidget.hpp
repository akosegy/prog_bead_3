#ifndef BASEWIDGET_HPP_INCLUDED
#define BASEWIDGET_HPP_INCLUDED

#include "graphics.hpp"

class Widget{
protected:
    int _x, _y, _width, _height;
    bool _selected;
public:
    Widget(int x, int y, int width, int height);
    virtual bool is_present(int, int);
    virtual void draw() = 0;
    virtual void handle(genv::event) = 0;
    virtual void select();
    virtual void deselect();
    virtual int get_x();
    virtual int get_y();
    virtual int get_width();
    virtual int get_height();
};

#endif // BASEWIDGET_HPP_INCLUDED
