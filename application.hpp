#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "menuwindow.hpp"
#include <vector>

using namespace std;

class Application{
protected:
    Main_menu * _menu;
    Game * _active_game;
    Victory * _victory_screen;
    Opener * _open_screen;
    Stages * _stage_selector;
    genv::event _ev;

public:
    int window_width;
    int window_height;

    Application();
    virtual void run();
    virtual void start_game(vector<int>);
    virtual void victory();
    virtual void activate_menu();
    virtual void show_stages();
    virtual void open();
    virtual void stop();
};

#endif // APPLICATION_HPP_INCLUDED
