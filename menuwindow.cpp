#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "menuwindow.hpp"
#include "graphics.hpp"
#include "application.hpp"

#include <functional>
#include <vector>

using namespace std;
using namespace genv;

Main_menu::Main_menu(string title, function<void()> stages_func, function<void()> open_func, function<void()> exit_func): Window(title){

    _stages_btn = new Button(50, 50, 100, 50, "Stages",
                       [=](){stages_func();});

    _open_btn = new Button(50, 50, 100, 101, "Open file",
                       [=](){open_func();});

    _exit_btn = new Button(50, 50, 100, 152, "Exit",
                       [=](){exit_func();});
}

void Main_menu::draw(){
    _stages_btn->draw();
    _open_btn->draw();
    _exit_btn->draw();
}

void Main_menu::handle(event ev){
    _stages_btn->handle(ev);
    _open_btn->handle(ev);
    _exit_btn->handle(ev);
}
