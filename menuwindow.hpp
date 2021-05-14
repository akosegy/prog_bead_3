#ifndef MENUWINDOW_HPP_INCLUDED
#define MENUWINDOW_HPP_INCLUDED

#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "application.hpp"
#include <functional>
#include <vector>

using namespace std;

class Main_menu : public Window {
protected:
    Button * _stages_btn;
    Button * _open_btn;
    Button * _exit_btn;
public:
    Main_menu(string title, function<void()> stages_func, function<void()> open_func, function<void()> exit_func);
    virtual void draw() override;
    virtual void handle(genv::event) override;
};


#endif // MENUWINDOW_HPP_INCLUDED
