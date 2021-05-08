#include "graphics.hpp"
#include "buttonwidget.hpp"
#include <functional>

using namespace genv;

Button::Button(int x, int y,int width, int height, string title, function<void()> func) : Widget(x, y, width, height), _title(title), _func(func)
{
    _pushed = false;
}

void Button::draw(){
    int font_width = gout.twidth(_title);
    int text_pos_x = _x + (_width / 2) - (font_width / 2);
    int text_pos_y = _y + (_height / 2) + (gout.cascent() / 2);

    gout << color(0,0,0)<< move_to(_x, _y) << box(_width, _height);

    if (_pushed){
        gout << color(100,100,100);
    }else{
        gout << color(200,200,200);
    }
    gout << move_to(_x+1, _y+1) << box(_width-2, _height-2) << move_to(text_pos_x, text_pos_y) << color(0,0,0) << text(_title);
}

void Button::push(){
    _func();
}

void Button::set_pushed(bool new_pushed){
    _pushed = new_pushed;
}

void Button::reset(){
    _pushed = false;
}

bool Button::is_pushed(){
    return _pushed;
}

void Button::set_title(string new_title){
    _title = new_title;
}

void Button::handle(event ev){
    if (ev.type == ev_mouse && ev.button==btn_left){
        if (is_present(ev.pos_x, ev.pos_y)){
            push();
        }
    }
}
