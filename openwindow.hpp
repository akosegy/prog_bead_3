#ifndef OPENWINDOW_HPP_INCLUDED
#define OPENWINDOW_HPP_INCLUDED

#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "textwidget.hpp"
#include <functional>

using namespace std;

class Open_window : public Window {
protected:
    Button * _submit_btn;
    Text * _textfield;

public:
    Open_window(string title, function<void()> submit_func);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual string get_textfield_text();
};

#endif // OPENWINDOW_HPP_INCLUDED
