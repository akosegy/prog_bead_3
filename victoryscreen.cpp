#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "victoryscreen.hpp"
#include "graphics.hpp"
#include "application.hpp"

#include <functional>

using namespace std;
using namespace genv;

Victory_window::Victory_window(string title, Application parent): Window(title, parent){

    _menu_btn = new Button(50, 50, 150, 70, "Menu",
                       [=](){_parent->set_window(MENU);});
    _exit_btn = new Button(50, 50, 150, 130, "Exit",
                       [=](){_parent->stop()});
}

void Victory_window::draw(){
    gout << color(255,255,255) << move_to(0,0)<< text(_title);

    _textfield->draw();
    _submit_btn->draw();
}

void Victory_window::handle(event ev){
    _textfield->handle(ev);
    _submit_btn->handle(ev);
}
