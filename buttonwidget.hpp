#ifndef BUTTONWIDGET_HPP_INCLUDED
#define BUTTONWIDGET_HPP_INCLUDED

#include "basewidget.hpp"
#include <functional>

using namespace std;

class Button : public Widget {
protected:
    string _title;
    bool _pushed;
    function<void()> _func;

public:
    Button(int , int ,int , int , string, function<void()>);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual void push();
    virtual bool is_pushed();
    virtual void set_pushed(bool);
    virtual void reset();
    virtual void set_title(string);
};

#endif // BUTTONWIDGET_HPP_INCLUDED
