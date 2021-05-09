#include "numericwidget.hpp"
#include "basewidget.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;

SPart::SPart(int x, int y, int height, int minimum, vector<Numeric *> data): Widget(x, y, width, height), _data(data){

}

void SPart::check_data(){

}

void SPart::handle(event ev){
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
        if (ev.keycode == key_enter){
            deselect();
        }
    }
}
