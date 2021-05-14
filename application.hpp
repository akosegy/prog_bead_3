#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "menuwindow.hpp"
#include <vector>

using namespace std;

enum window_list{
    MENU,
    STAGES,
    OPEN,
    VICTORY
    OTHER
};

class Application{
protected:
    Window * _present;
    Main_menu * _menu;
    Game * _active_game;
    Victory * _victory_screen;
    Opener * _open_screen;
    Stages * _stage_selector;
    genv::event _ev;

    vector<int> _read_file_data(string file_name);

public:
    int window_width;
    int window_height;

    Application();
    virtual void run();
    virtual void start_game(string file_name);
    virtual void victory();
    virtual void activate_menu();
    virtual void show_stages();
    virtual void open();
    virtual void stop();
};

#endif // APPLICATION_HPP_INCLUDED
