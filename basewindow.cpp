#include "graphics.hpp"
#include "basewindow.hpp"

using namespace genv;

Window::Window(string title): _title(title)
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

