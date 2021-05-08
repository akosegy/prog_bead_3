#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "menuwindow.hpp"

class Application{
protected:
    Main_menu * _menu;
    genv::event _ev;

public:
    int window_width;
    int window_height;

    Application();
    virtual void run();
    virtual void stop();
};

#endif // APPLICATION_HPP_INCLUDED
