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
    }else{
        wrong_data();
    }
}

void Game::wrong_data(){
    gout << color(255,0,0) << move_to(0, 0) << box(100,50);
    gout << color(0,0,0) << move_to(10, 10) << text("wrong input data");
}
