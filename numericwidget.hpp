#ifndef NUMERICWIDGET_HPP_INCLUDED
#define NUMERICWIDGET_HPP_INCLUDED

#include "basewidget.hpp"
#include "buttonwidget.hpp"

class Numeric : public Widget {
protected:
    int _r, _g, _b;
    bool _hide_buttons;
    bool _editable;
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
    virtual void set_color(int, int, int);
    virtual void set_value(int);
    virtual void set_editable(bool);
};


#endif // NUMERICWIDGET_HPP_INCLUDED
