#include "graphics.hpp"
#include "buttonwidget.hpp"
#include "numericwidget.hpp"
#include "sstream"

using namespace genv;

Numeric::Numeric(int x, int y,int width, int height,int minimum, int maximum, bool hide_buttons) : Widget(x, y, width, height), _minimum(minimum), _maximum(maximum), _hide_buttons(hide_buttons){
    int button_x = x + width - height/2;
    string text_up;
    string text_down;
    _r = 255;
    _g = 255;
    _b = 255;
    if (_hide_buttons){
        _buttonsize = 0;

    }else{
        _buttonsize = height/2;
    }
    _up = new Button(button_x, y, _buttonsize, _buttonsize, "A",
                    [this](){_up_button_function();});
    _down = new Button(button_x, y+_buttonsize, _buttonsize, _buttonsize, "V",
                    [this](){_down_button_function();});

    if (_minimum < 0  && _maximum > 0){
        _counter = 0;
    }else if(_minimum > 0){
        _counter = _minimum;
    }else if(_maximum < 0){
        _counter =_maximum;
    }

}

void Numeric::_up_button_function(){
    add(1);
}

void Numeric::_down_button_function(){
    add(-1);
}

void Numeric::draw(){
    stringstream ss;
    int font_width;
    int text_pos_x;
    int text_pos_y;

    ss << _counter;

    font_width = gout.twidth(ss.str());
    text_pos_x = _x + (_width / 2) - (font_width / 2);
    text_pos_y = _y + (_height / 2) + (gout.cascent() / 2);

    gout << color(0,0,0) << move_to(_x, _y )<< box(_width - _buttonsize, _height);
    gout << color(_r,_g,_b) << move_to(_x+1, _y+1) << box((_width - _buttonsize)-2, _height-2) << move_to(text_pos_x, text_pos_y) << color(0,0,0) << text(ss.str());

    if (_buttonsize>0){
        _up->draw();
        _down->draw();
    }
}

void Numeric::add(int a){
    if (_counter + a >= _minimum && _counter + a <= _maximum){
        _counter = _counter + a;
    }
}

void Numeric::give(int a){
    if (_counter * 10 + a >= _minimum && _counter * 10 + a <= _maximum){
        _counter = _counter * 10 + a;
    }
}

int Numeric::get_saveable(){
    return _counter;
}

void Numeric::set_color(int r, int g, int b){
    _r = r;
    _g = g;
    _b = b;
}

void Numeric::set_value(int new_value){
    if (new_value >= _minimum && new_value <= _maximum){
        _counter = new_value;
    }
}

void Numeric::handle(event ev){
    if (ev.type == ev_mouse) {
        if (ev.button == btn_left){
            if (is_present(ev.pos_x, ev.pos_y)){
                select();
                _up->handle(ev);
                _down->handle(ev);
            }else{
                deselect();
            }
        }
    }else if (_selected){
        if (ev.type == ev_key){
            if (ev.keycode == key_up){
                add(1);
            }else if (ev.keycode == key_down){
                add(-1);
            }else if (ev.keycode == key_pgdn){
                add(-10);
            }else if (ev.keycode == key_pgup){
                add(10);
            }else if (ev.keycode > 47 && ev.keycode < 58){
                give(ev.keycode-48);
            }else if (ev.keycode == key_backspace){
                if (((_counter / 10) >= _minimum && _counter > 0) || ((_counter / 10) <= _maximum && _counter < 0)){
                        _counter = _counter / 10;
                }
            }else if (ev.keycode == key_enter){
                deselect();
            }
        }
    }
}
