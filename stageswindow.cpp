#include "buttonwidget.hpp"
#include "basewindow.hpp"
#include "stageswindow.hpp"
#include "graphics.hpp"
#include "application.hpp"

#include <functional>
#include <vector>

using namespace std;
using namespace genv;

Stages_menu::Stages_menu(string title, Application parent): Window(title, parent){

    _stage_1_data = "stage1.txt";
    _stage_2_data = "stage2.txt";
    _stage_3_data = "stage3.txt";

    _stage_1_btn = new Button(50, 50, 100, 50, "Stage 1",
                       [=](){_btn_function->start_game(_stage_1_data);});

    _stage_2_btn = new Button(50, 50, 100, 101, "Stage 2",
                       [=](){_parent->start_game(_stage_2_data);});

    _stage_3_btn = new Button(50, 50, 100, 152, "Stage 3",
                       [=](){_parent->start_game(_stage_3_data);});
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
