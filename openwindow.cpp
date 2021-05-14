#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "openwindow.hpp"
#include "graphics.hpp"
#include "application.hpp"
#include "textwidget.hpp"

#include <functional>
#include <vector>

using namespace std;
using namespace genv;

Open_window::Open_window(string title, Application parent): Window(title, parent){

    _textfield = new text(250, 50, 10, 50, "Please type the path here", true);

    _submit_btn = new _submit_btn(50, 50, 270, 50, "Submit",
                       [=](){_parent->start_game(_textfield->get_text()));});
}

void Open_window::draw(){
    _textfield->draw();
    _submit_btn->draw();
}

void Open_window::handle(event ev){
    _textfield->handle(ev);
    _submit_btn->handle(ev);
}
