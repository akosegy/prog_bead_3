#include "textwidget.hpp"
#include "graphics.hpp"

using namespace genv;

Text::Text(int x, int y,int width, int height, string text, bool is_input): Widget(x, y, width, height), _text(text), _is_input(is_input){
}

void Text::draw(){
    gout << color(0,0,0) << move_to(_x, _y )<< box(_width, _height);
    int text_pos_x = _x + 5;
    int text_pos_y = _y + (_height / 2) + (gout.cascent() / 2);

    if (_selected){
        gout << color(255,255,255);
    }else{
        gout << color(240,240,240);
    }
    gout << move_to(_x+1, _y+1) << box((_width)-2, _height-2) << move_to(text_pos_x, text_pos_y) << color(0,0,0) << text(_text);
}

string Text::get_text(){
    return _text;
}

void Text::set_text(string new_text){
    _text = new_text;
}

void Text::handle(event ev){
    if (_is_input){
        if (ev.type == ev_mouse && ev.button==btn_left){
            if (is_present(ev.pos_x, ev.pos_y)){
                select();
            }
        }else if(_selected){
            if((ev.keycode == key_backspace) && (_text.size() != 0)){
                _text.pop_back();
            }else if (ev.keycode>0 and ev.keycode<256){
                _text += ev.keycode;
            }
        }
    }
}
