#ifndef GAMEWINDOW_HPP_INCLUDED
#define GAMEWINDOW_HPP_INCLUDED

#include "basewindow.hpp"
#include "numericwidget.hpp"
#include "sudokupart.hpp"
#include <vector>

using namespace std;

class Game : public Window {
protected:
    vector<Numeric *> _cells;
    vector<SPart *> _rows;
    vector<SPart *> _columns;
    vector<SPart *> _squares;
public:
    Game(string, vector<int>);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual void wrong_data();


};

#endif // GAMEWINDOW_HPP_INCLUDED
