#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "stageswindow.hpp"
#include "graphics.hpp"
#include "application.hpp"

#include <functional>
#include <vector>

using namespace std;
using namespace genv;

Stages_menu::Stages_menu(string title, function<void()> stage_1_func, function<void()> stage_2_func, function<void()> stage_3_func): Window(title){

    _stage_1_btn = new Button(50, 50, 100, 50, "Stage 1",
                       [=](){stage_1_func;});

    _stage_2_btn = new Button(50, 50, 100, 101, "Stage 2",
                       [=](){stage_2_func;});

    _stage_3_btn = new Button(50, 50, 100, 152, "Stage 3",
                       [=](){stage_3_func;});
}

void Stages_menu::draw(){
    _stage_1_btn->draw();
    _stage_2_btn->draw();
    _stage_3_btn->draw();
}

void Stages_menu::handle(event ev){
    _stage_1_btn->handle(ev);
    _stage_2_btn->handle(ev);
    _stage_3_btn->handle(ev);
}
