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

    virtual void _generate_rows(vector<Numeric *>);
    virtual void _generate_columns(vector<Numeric *>);
    virtual void _generate_squares(vector<Numeric *>);
    virtual bool _handle_mistakes();
    void _victory_func();
public:
    Game(string, vector<int>, function<void()> victory_func);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual void wrong_data();


};

#endif // GAMEWINDOW_HPP_INCLUDED
