#include "graphics.hpp"
#include "application.hpp"
#include "basewindow.hpp"
#include "menuwindow.hpp"
#include "gamewindow.hpp"
#include "openwindow.hpp"
#include "stageswindow.hpp"
#include "victoryscreen.hpp"
#include <fstream>
#include <functional>

using namespace genv;
using namespace std;

Application::Application(){
    window_height = 400;
    window_width = 400;

    _stage_1_data = "stage1.txt";
    _stage_2_data = "stage2.txt";
    _stage_3_data = "stage3.txt";

    _menu = new Main_menu("Main menu",
                       [=](){set_window(STAGES);},
                       [=](){set_window(OPEN);},
                       [=](){stop();});

    _victory_screen = new Victory_window("Congratulations",
                                  [=](){set_window(STAGES);},
                                  [=](){stop();});

    _open_screen = new Open_window("Open screen",
                              [=](){start_game(_open_screen->get_textfield_text());});

    _stage_selector = new Stages_menu ("Stages",
                                  [=](){start_game(_stage_1_data);},
                                  [=](){start_game(_stage_2_data);},
                                  [=](){start_game(_stage_3_data);});

    _present = _menu;
    _present->unhide();
}

void Application::run(){
    gout.open(window_width,window_height);

    while (gin >> _ev){
        gout << color(255,255,255) << move_to(0,0)<< box(window_width,window_height);

        _present->handle(_ev);
        _present->draw();

        gout << refresh;
    }
}



void Application::start_game(string file_name){
    _active_game = new Game("Sudoku", _read_file_data(file_name),
                            [=](){set_window(VICTORY);});
    _present->hide();
    _present = _active_game;
    _present->unhide();
}

vector<int> Application::_read_file_data(string file_name){
    vector<int> par;
    ifstream saved;
    saved.open(file_name);

    while (saved.good()){
        int x;
        saved >> x;
        par.push_back(x);
    }

    return par;
}

void Application::set_window(window_list new_window){
    switch(new_window){
        case MENU:
            _present->hide();
            _present = _menu;
            _present->unhide();

            break;
        case STAGES:
            _present->hide();
            _present = _stage_selector;
            _present->unhide();

            break;
        case OPEN:
            _present->hide();
            _present = _open_screen;
            _present->unhide();

            break;
        case VICTORY:
            _present->hide();
            delete _active_game;
            _present = _victory_screen;
            _present->unhide();

            break;
        default:
            break;
    }
}

void Application::stop(){
    exit(0);
}
