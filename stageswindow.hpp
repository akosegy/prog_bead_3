#ifndef STAGESWINDOW_HPP_INCLUDED
#define STAGESWINDOW_HPP_INCLUDED

#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "application.hpp"
#include <functional>
#include <vector>

using namespace std;

class Stages_menu : public Window {
protected:
    Button * _stage_1_btn;
    Button * _stage_2_btn;
    Button * _stage_3_btn;

    void _btn_function;
public:
    Stages_menu(string title, Application parent);
    virtual void draw() override;
    virtual void handle(genv::event) override;
};


#endif // STAGESWINDOW_HPP_INCLUDED
