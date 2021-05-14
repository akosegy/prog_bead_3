#include "graphics.hpp"
#include "application.hpp"
#include "menuwindow.hpp"

using namespace genv;

Application::Application(){
    window_height = 400;
    window_width = 400;

    _menu = new Main_menu("Main menu");
    _menu->unhide();
}

void Application::run(){
    gout.open(window_width,window_height);

    while (gin >> _ev){
        gout << color(255,255,255) << move_to(0,0)<< box(window_width,window_height);

        if(!(_menu->is_hidden())){
            _menu->handle(_ev);
            _menu->draw();
        }

        gout << refresh;
    }
}



void Application::start_game(vector<int>){
}
void Application::victory()
void Application::activate_menu()
void Application::show_stages()
void Application::open()

void Application::stop(){
    exit(0);
}
