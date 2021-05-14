#ifndef OPENWINDOW_HPP_INCLUDED
#define OPENWINDOW_HPP_INCLUDED

#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "application.hpp"
#include "textwidget.hpp"
#include <functional>
#include <vector>

using namespace std;

class Open_window : public Window {
protected:
    Button * _submit_btn;
    Text * _textfield;

    void _submit;
public:
    Open_window(string title, Application parent);
    virtual void draw() override;
    virtual void handle(genv::event) override;
};

#endif // OPENWINDOW_HPP_INCLUDED
