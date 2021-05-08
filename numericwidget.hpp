#ifndef NUMERICWIDGET_HPP_INCLUDED
#define NUMERICWIDGET_HPP_INCLUDED

#include "basewidget.hpp"
#include "buttonwidget.hpp"

class Numeric : public Widget {
protected:
    bool _hide_buttons;
    int _buttonsize;
    int _counter;
    int _minimum;
    int _maximum;
    Button *_up;
    Button *_down;
    void _down_button_function();
    void _up_button_function();
public:
    Numeric(int, int, int, int, int, int, bool);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual void add(int);
    virtual void give(int);
    virtual int get_saveable();
};


#endif // NUMERICWIDGET_HPP_INCLUDED
