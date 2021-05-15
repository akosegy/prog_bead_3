#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "basewindow.hpp"
#include "menuwindow.hpp"
#include "gamewindow.hpp"
#include "openwindow.hpp"
#include "stageswindow.hpp"
#include "victoryscreen.hpp"
#include <vector>

using namespace std;

enum window_list{
    MENU,
    STAGES,
    OPEN,
    VICTORY,
    OTHER
};

class Application{
protected:
    string _stage_1_data;
    string _stage_2_data;
    string _stage_3_data;

    Window * _present;
    Main_menu * _menu;
    Game * _active_game;
    Open_window * _open_screen;
    Stages_menu * _stage_selector;
    Victory_window * _victory_screen;
    genv::event _ev;

    vector<int> _read_file_data(string file_name);

public:
    int window_width;
    int window_height;

    Application();
    virtual void run();
    virtual void start_game(string file_name);
    virtual void stop();
    virtual void set_window(window_list new_window);
};

#endif // APPLICATION_HPP_INCLUDED
