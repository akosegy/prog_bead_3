#ifndef VICTORYSCREEN_HPP_INCLUDED
#define VICTORYSCREEN_HPP_INCLUDED

#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "application.hpp"
#include <functional>

using namespace std;

class Victory_window : public Window {
protected:
    Button * _menu_btn;
    Button * _exit_btn;

public:
    Victory_window(string title, function<void()> menu_func, function<void()> exit_func);
    virtual void draw() override;
    virtual void handle(genv::event) override;
};

#endif // VICTORYSCREEN_HPP_INCLUDED
