#include "graphics.hpp"
#include "basewindow.hpp"
#include "application.hpp"

using namespace genv;

Window::Window(string title, Application * parent): _title(title), _parent(parent)
{
    _hidden = true;
}

bool Window::is_hidden(){
    return _hidden;
}

void Window::hide(){
    _hidden = true;
}

void Window::unhide(){
    _hidden = false;
}

