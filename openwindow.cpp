#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "openwindow.hpp"
#include "graphics.hpp"
#include "application.hpp"
#include "textwidget.hpp"

#include <functional>

using namespace std;
using namespace genv;

Open_window::Open_window(string title, function<void()> submit_func): Window(title){

    _textfield = new Text(250, 50, 10, 50, "Please type the path here", true);

    _submit_btn = new Button(50, 50, 270, 50, "Submit",
                       [=](){submit_func;});
}

string Open_window::get_textfield_text(){
    return _textfield->get_text();
}

void Open_window::draw(){
    _textfield->draw();
    _submit_btn->draw();
}

void Open_window::handle(event ev){
    _textfield->handle(ev);
    _submit_btn->handle(ev);
}
