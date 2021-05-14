#ifndef BASEWINDOW_HPP_INCLUDED
#define BASEWINDOW_HPP_INCLUDED

#include "graphics.hpp"
#include "application.hpp"

using namespace std;

class Window{
protected:
    string _title;
    bool _hidden;
    Application _parent;
public:
    Window(string title, Application * parent);
    virtual bool is_hidden();
    virtual void draw() = 0;
    virtual void handle(genv::event) = 0;
    virtual void hide();
    virtual void unhide();
};


#endif // BASEWINDOW_HPP_INCLUDED
