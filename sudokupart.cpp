#include "numericwidget.hpp"
#include "basewidget.hpp"
#include "graphics.hpp"
#include <vector>
#include <algorithm>

using namespace genv;
using namespace std;

SPart::SPart(int x, int y, int height, int minimum, vector<Numeric *> data): Widget(x, y, width, height), _data(data){

}

vector<Numeric *> SPart::check_data(){
    vector<Numeric *> wrongs;

    for (int i = 0; i < _data.size(); i++){
        for (int j = _data.size()-(i+1); j > i); j--){
            if (_data[i]->get_saveable() == _data[j]->get_saveable()){
                if (find(wrongs.begin(), wrongs.end(), _data[i]) == wrongs.end() ){
                    wrongs.push_back(_data[i]);
                }
                if (find(wrongs.begin(), wrongs.end(), _data[j]) == wrongs.end()){
                    wrongs.push_back(_data[j]);
                }
            }
        }
    }
    return wrongs;
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
                //check_data();
            }
        }
    }else if (_selected){
        if (ev.keycode == key_enter){
            deselect();
        }
    }
}
