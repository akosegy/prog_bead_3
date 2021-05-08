#ifndef MENUWINDOW_HPP_INCLUDED
#define MENUWINDOW_HPP_INCLUDED

#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "dropdownwidget.hpp"
#include "numericwidget.hpp"
#include "textwidget.hpp"
#include <functional>
#include <vector>

using namespace std;

class Main_menu : public Window {
protected:
    Button * _btn_1;
    Text * _text_in;

    void _buttonfunction();
public:
    Main_menu(string);
    virtual void draw() override;
    virtual void handle(genv::event) override;
};


#endif // MENUWINDOW_HPP_INCLUDED
