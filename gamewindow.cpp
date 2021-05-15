#include "basewindow.hpp"
#include "numericwidget.hpp"
#include "sudokupart.hpp"
#include "gamewindow.hpp"
#include "graphics.hpp"
#include <vector>
#include <functional>

#include <iostream>

using namespace std;
using namespace genv;

Game::Game(string title, vector<int> data, function<void()> victory_func): Window(title), _victory_func(victory_func){
    if (data.size() == 81){
        _wrong_data = false;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                Numeric * cell = new Numeric(1+j*40, 1+i*40, 38, 38, 0, 9, true);
                cell->set_value(data[i*9+j]);
                if (data[i*9+j] != 0){
                        cell->set_editable(false);

                }
                _cells.push_back(cell);
            }
        }
        _generate_rows(_cells);
        _generate_columns(_cells);
        _generate_squares(_cells);
    }else{
        _wrong_data = true;
    }
}

//Game::~Game(){
//    for (int i = 8; i > -1; i--){
//        delete _rows[i];
//        delete _columns[i];
//        delete _squares[i];
//    }
//
//    for (int i = _cells.size()-1; i > -1; i--){
//        delete _cells[i];
//    }
//}


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

        x = par[0]->get_x()-1;
        y = par[0]->get_y()-1;
        width = par[8]->get_x() + par[8]->get_width() - x+1;
        height = par[8]->get_y() + par[8]->get_height() - y+1;
        _rows.push_back(new SPart(x, y, height, width, par));
    }
}
void Game::_generate_columns(vector<Numeric *> data){
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
        width = par[8]->get_x() + par[8]->get_width() - x;
        height = par[8]->get_y() + par[8]->get_height() - y;
        _columns.push_back(new SPart(x, y, height, width, par));
    }
}

void Game::_generate_squares(vector<Numeric *> data){
    int x;
    int y;
    int height;
    int width;

    for (int field_columns = 0; field_columns < 3; field_columns++){
        for (int field_row = 0; field_row < 3; field_row++){
            vector<Numeric *> par;
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    par.push_back(data[9 * (field_columns*3 + j) + field_row*3 + i]);
                }
            }

            x = par[0]->get_x();
            y = par[0]->get_y();
            width = par[8]->get_x() + par[8]->get_width() - x;
            height = par[8]->get_y() + par[8]->get_height() - y;
            _squares.push_back(new SPart(x, y, height, width, par));
        }
    }
}

bool Game::_handle_mistakes(){
    vector<Numeric *> mistakes;
    for (int i = 0; i < 9; i++){
        vector<Numeric *> par;
        par = _rows[i]->check_data();
        mistakes.insert(mistakes.end(), par.begin(), par.end());
        par =_columns[i]->check_data();
        mistakes.insert(mistakes.end(), par.begin(), par.end());
        par = _squares[i]->check_data();
        mistakes.insert(mistakes.end(), par.begin(), par.end());
    }
    int n = mistakes.size();

    for(int i = 0; i < _cells.size(); i++){
        _cells[i]->set_color(0,0,0);
    }
    if (mistakes.empty()){
        return true;
    }else{
        for(int i = 0; i < mistakes.size(); i++){
            mistakes[i]->set_color(255,0,0);
        }
        return false;
    }
}

bool Game::check_nulls(){
    for (int i = 0; i < _cells.size(); i++){
        if (_cells[i]->get_saveable() == 0){
            return true;
        }
    }
    return false;
}

void Game::draw(){
    if (_wrong_data){
        gout << color(250,0,0) << move_to(10, 50) << text("wrong input data");
    }else{
        for (int i= 0; i<9; i++){
            _squares[i]->draw();
        }

        for (int i = 0; i < _cells.size(); i++){
            _cells[i]->draw();
        }
    }
}

void Game::handle(event ev){
    if (_wrong_data){

    }else{
        for(int i = 0; i < _cells.size(); i++){
            _cells[i]->handle(ev);
        }

        if (ev.type == ev_mouse) {
            if (ev.button == btn_left){
                if (_handle_mistakes() && !check_nulls()){
                    _victory_func();
                }
            }
        }else if (ev.type == ev_key){
            if (ev.keycode == key_enter){
                if (_handle_mistakes() && !check_nulls()){
                    _victory_func();
                }
            }
        }
    }
}
