#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "menuwindow.hpp"
#include "numericwidget.hpp"
#include "graphics.hpp"
#include "dropdownwidget.hpp"
#include "textwidget.hpp"

#include <functional>
#include <vector>

using namespace std;
using namespace genv;

Main_menu::Main_menu(string title): Window(title){

    _btn_1 = new Button(50, 100, 100, 50, "Button",
                       [this](){_buttonfunction();});

    _text_in = new Text(10, 10, 200, 50, "please type here", true);
}

void Main_menu::_buttonfunction(){
    _btn_1->set_title(_text_in->get_text());
}

void Main_menu::draw(){
    _btn_1->draw();
    _text_in->draw();
}

void Main_menu::handle(event ev){
    _btn_1->handle(ev);
    _text_in->handle(ev);
}
