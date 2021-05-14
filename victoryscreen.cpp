#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "victoryscreen.hpp"
#include "graphics.hpp"
#include "application.hpp"

#include <functional>

using namespace std;
using namespace genv;

Victory_window::Victory_window(string title, function<void()> menu_func, function<void()> exit_func): Window(title){

    _menu_btn = new Button(50, 50, 150, 70, "Menu",
                       [=](){menu_func();});
    _exit_btn = new Button(50, 50, 150, 130, "Exit",
                       [=](){exit_func();});
}

void Victory_window::draw(){
    gout << color(255,255,255) << move_to(0,0)<< text(_title);

    _menu_btn->draw();
    _exit_btn->draw();
}

void Victory_window::handle(event ev){
    _menu_btn->handle(ev);
    _exit_btn->handle(ev);
}
