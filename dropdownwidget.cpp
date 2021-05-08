#include "graphics.hpp"
#include "buttonwidget.hpp"
#include "dropdownwidget.hpp"

using namespace genv;

Dropdown::Dropdown(int x, int y, int width, vector<string> options, int dropdown_rows)
    : Widget(x, y, width, (gout.cascent() + gout.cdescent() + 2)), _options(options), _dropdown_rows(dropdown_rows){

    int button_x = x + width - _height;
    _opener = new Button(button_x, y, _height, _height, "V", [this](){_opener_button_function();});

    _active = "";
    _current = 0;
    _opened_height = (gout.cascent() + gout.cdescent())*(_dropdown_rows+1)+4;

}

void Dropdown::_opener_button_function(){
    _opener->set_pushed(!(_opener->is_pushed()));
}

void Dropdown::draw(){
    int font_height = gout.cascent()+ gout.cdescent();

    if (_opener->is_pushed()){

        gout << color(0,0,0) << move_to(_x, _y) << box(_width - _height, _opened_height);
        gout << color(255,255,255) << move_to(_x+1, _y+1) << box((_width - _height) - 2, _opened_height - 2);
        gout << move_to(_x + 3, _y + 2 + gout.cascent()) << color(0,0,0) << text(_active);

        for (int i =0; i < _dropdown_rows; i++){
            gout << move_to(_x + 3, _y + 2 + font_height*(i+2)) << text(_options[_current+i]);
        }

    }else{
        close();

        gout << color(0,0,0) << move_to(_x, _y) << box(_width - _height, _height);
        gout << color(255,255,255) << move_to(_x+1, _y+1) << box((_width - _height) - 2, _height - 2);
        gout << move_to(_x + 3, _y + 2 + gout.cascent()) << color(0,0,0) << text(_active);
    }

    _opener->draw();
}


void Dropdown::close(){
    _current = 0;
    _opener -> reset();
}

void Dropdown::choose(int i){
    _active = _options[_current+i];
    close();
}

void Dropdown::scroll(bool up){
    if (up){
        if (_current>0){
            _current--;
        }
    }else{
        int last = _options.size()- _dropdown_rows;
        if (_current< last){
            _current++;
        }
    }
}

bool Dropdown::is_dropdown_present(int mouse_pos_x, int mouse_pos_y){
    if (_opener->is_pushed()){
        return mouse_pos_x>_x && mouse_pos_x<_x+_width-_height && mouse_pos_y>_y+_height && mouse_pos_y<_y+_opened_height;
    }else{
        return false;
    }
}

string Dropdown::get_saveable(){
    return _active;
}

void Dropdown::handle(event ev){
    if (ev.type == ev_mouse) {
        if (ev.button == btn_left){
            if (is_present(ev.pos_x, ev.pos_y)){
                select();
                _opener->handle(ev);
            }else if(is_dropdown_present(ev.pos_x, ev.pos_y)){
                int par = ev.pos_y - (_y + (gout.cascent() + gout.cdescent() + 2));
                choose(par / (gout.cascent() + gout.cdescent()));
            }else{
                close();
                _opener -> reset();
                deselect();
            }
        }else if (_selected){
            if (ev.button == btn_wheelup){
                scroll(true);
            }else if (ev.button == btn_wheeldown){
                scroll(false);
            }
        }
    }else if (_selected){
        if (ev.type == ev_key){
            if (ev.keycode == key_up){
                scroll(true);
            }else if (ev.keycode == key_down){
                scroll(false);
            }
        }
    }
}
