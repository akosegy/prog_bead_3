#include "graphics.hpp"
#include "application.hpp"
#include "menuwindow.hpp"
#include <iostream>

using namespace genv;

Application::Application(){
    window_height = 400;
    window_width = 400;

    _menu = new Main_menu("Main menu");
    _victory_screen = new Victory("Congratulations");
    _open_screen = new Opener("Open screen")
    _stage_selector = new Stages ("Stages");

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
    _active_game = new Game("Sudoku", _read_file_data(file_name));
    present->hide(true);
    present = _active_game;
    present->hide(false);
}

vector<int> Application::_read_file_data(string file_name){
    vector<int> par;
    ifstream save;
    save.open(file_name);

    while (save.good()){
        int x;
        save >> x;
        par-push_back(x);
    }

    retun par;
}

void Application::set_window(window_list new_window){
    switch(new_window){
        case MENU:
            present->hide(true);
            present = _menu;
            present->hide(false);

            break;
        case STAGES:
            present->hide(true);
            present = _stage_selector;
            present->hide(false);

            break;
        case OPEN:
            present->hide(true);
            present = _open_screen;
            present->hide(false);

            break;
        case VICTORY:
            present->hide(true);
            delete _active_game;
            present = _victory_screen;
            present->hide(false);

            break;
        default:
            break;
    }
}

void Application::stop(){
    exit(0);
}
