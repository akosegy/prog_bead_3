#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "menuwindow.hpp"
#include "graphics.hpp"
#include "application.hpp"

#include <functional>
#include <vector>

using namespace std;
using namespace genv;

Main_menu::Main_menu(string title, Application parent): Window(title, parent){

    _stages_btn = new Button(50, 50, 100, 50, "Button",
                       [=](){_parent->show_stages();});

    _open_btn = new Button(50, 50, 100, 50, "Button",
                       [=](){_parent->open();});
    _exit_btn = new Button(50, 50, 100, 50, "Button",
                       [=](){_parent->stop();});
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
