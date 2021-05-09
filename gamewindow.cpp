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

    for (int i = 0; i < 9; i++){                                                             //to do
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

void Game::_generate_squares(vector<Numeric *>){                                             //to do
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
