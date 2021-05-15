#include "numericwidget.hpp"
#include "basewidget.hpp"
#include "graphics.hpp"
#include "sudokupart.hpp"
#include <vector>

using namespace genv;
using namespace std;

SPart::SPart(int x, int y, int height, int width, vector<Numeric *> data): Widget(x, y, width, height), _data(data){

}

SPart::~SPart(){
    for (int i = _data.size()-1; i > -1; i--){
        delete _data[i];
    }
}

vector<Numeric *> SPart::check_data(){
    vector<Numeric *> wrongs;

    for (int i = 0; i < _data.size(); i++){
        for (int j = 0; j < _data.size(); j++){
            if(i!=j){
                if((_data[i]->get_saveable() != 0) && (_data[j]->get_saveable() != 0)){
                    if (_data[i]->get_saveable() == _data[j]->get_saveable()){
                        wrongs.push_back(_data[j]);
                        wrongs.push_back(_data[i]);
                    }
                }
            }

        }
    }
    return wrongs;
}

void SPart::draw(){
    gout << move_to(_x, _y)<< color(0,0,0)  << box(_width, _height);
    gout << move_to(_x+2, _y+2)<< color(100,100,100)  << box(_width-4, _height-4);
}

void SPart::handle(event ev){
    if (ev.type == ev_mouse) {
        if (ev.button == btn_left){
            if (is_present(ev.pos_x, ev.pos_y)){
                select();
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
