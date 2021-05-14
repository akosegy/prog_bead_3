#include "graphics.hpp"
#include "basewidget.hpp"

using namespace genv;

Widget::Widget(int x, int y, int width, int height) : _x(x), _y(y), _width(width), _height(height)
{
    _selected = false;
}

bool Widget::is_present(int mouse_pos_x, int mouse_pos_y){
    return mouse_pos_x>_x && mouse_pos_x<_x+_width && mouse_pos_y>_y && mouse_pos_y<_y+_height;
}

void Widget::select(){
    _selected = true;
}

void Widget::deselect(){
    _selected = false;
}

int Widget::get_x(){
    return _x;
}

int Widget::get_y(){
    return _y;
}
