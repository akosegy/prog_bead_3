#ifndef GAMEWINDOW_HPP_INCLUDED
#define GAMEWINDOW_HPP_INCLUDED

#include "basewindow.hpp"
#include "numericwidget.hpp"
#include "sudokupart.hpp"
#include <vector>
#include <functional>

using namespace std;

class Game : public Window {
protected:
    bool _wrong_data;
    vector<Numeric *> _cells;
    vector<SPart *> _rows;
    vector<SPart *> _columns;
    vector<SPart *> _squares;

    virtual void _generate_rows(vector<Numeric *>);
    virtual void _generate_columns(vector<Numeric *>);
    virtual void _generate_squares(vector<Numeric *>);
    virtual bool _handle_mistakes();
    function<void()> _victory_func;
public:
    Game(string, vector<int>, function<void()> victory_func);
    //virtual ~Game();
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual bool check_nulls();
};

#endif // GAMEWINDOW_HPP_INCLUDED
