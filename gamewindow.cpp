#include "basewindow.hpp"
#include "numericwidget.hpp"
#include "sudokupart.hpp"
#include "gamewindow.hpp"
#include "graphics.hpp"
#include <vector>

using namespace std;
using namespace genv;

Game::Game(string title, vector<int> data): Window(title){
    if (data.size() == 81){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                Numeric * cell = new Numeric(0+j*40, 0+i*40, 40, 40, 0, 9, true);
                if (data[i] != 0){
                        cell->set_editable(false);
                }
                _cells.push_back(cell);
            }
        }
        _generate_rows(_cells);
        _generate_columns(_cells);
        _generate_squares(_cells);
    }else{
        wrong_data();
    }
}

void Game::wrong_data(){
    gout << color(255,0,0) << move_to(0, 0) << box(100,50);
    gout << color(0,0,0) << move_to(10, 10) << text("wrong input data");
}

void Game::_generate_rows(vector<Numeric *> data){
    int x;
    int y;
    int height;
    int width;

    for (int i = 0; i < 9; i++){

        vector<Numeric *> par;

        for (int j = 0; j < 9; j++){
            par.push_back(data[j+ i*9]);
        }

        x = par[0]->get_x();
        y = par[0]->get_y();
        width = par[0]->get_x() - x;
        height = par[0]->get_y() - y;
        _rows.push_back(new SPart(x, y, height, width, par));
    }
}
void Game::_generate_columns(vector<Numeric *>){
    int x;
    int y;
    int height;
    int width;

    for (int i = 0; i < 9; i++){
        vector<Numeric *> par;

        for (int j = 0; j < 9; j++){
            par.push_back(data[j * 9 + i]);
        }

        x = par[0]->get_x();
        y = par[0]->get_y();
        width = par[0]->get_x() - x;
        height = par[0]->get_y() - y;
        _columns.push_back(new SPart(x, y, height, width, par));
    }
}

void Game::_generate_squares(vector<Numeric *>){
    int x;
    int y;
    int height;
    int width;

    for (int field_columns = 0; field_columns < 3; field_columns++){
        for (int field_row = 1; field_row < 4; field_row++){
            vector<Numeric *> par;
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++{
                    par.push_back(data[field_row * i * 3 + j + field_columns * 27]);
                }
            }

            x = par[0]->get_x();
            y = par[0]->get_y();
            width = par[0]->get_x() - x;
            height = par[0]->get_y() - y;
            _squares.push_back(new SPart(x, y, height, width, par));
        }
    }
}

bool _handle_mistakes(){
    vector<Numeric *> mistakes;
    for (int i = 0; i < 9; i++){
        mistakes.push_back(_rows[i]->check_data());
        mistakes.push_back(_columns[i]->check_data());
        mistakes.push_back(_squares[i]->check_data());
    }
    int n = mistakes.size();
    while (n >= 0){
        if (find(mistakes.begin(), mistakes.end(), mistakes[n]) != n){
            mistakes.erase(mistakes.begin()+n);
        }
        n--;
    }
    for(int i = 0; i < _cells.size(); i++){
        _cells[i]->set_color(0,0,0);
    }
    if (mistakes.empty){
        return true;
    }else{
        for(int i = 0; i < mistakes.size(); i++){
            mistakes[i]->set_color(255,0,0);
        }
        return false;
    }
}

void Game::draw(){
    for (int i = 0; i < _cells.size(); i++){
        _cells[i]->draw();
    }
}

void Game::handle(event ev){
    for(int i = 0; i < _cells.size(); i++){
        _cells[i]->handle(ev);
    }

    if (ev.type == ev_mouse) {
        if (ev.button == btn_left){
            if (_handle_mistakes()){
                _parent->victory();
            }
        }
    }else if (ev.type == ev_key){
        if (ev.keycode == key_enter){
            if (_handle_mistakes()){
                _parent->victory();
            }
        }
    }
}
