#ifndef DROPDOWNWIDGET_HPP_INCLUDED
#define DROPDOWNWIDGET_HPP_INCLUDED

#include "basewidget.hpp"
#include "buttonwidget.hpp"
#include <vector>

class Dropdown : public Widget {
protected:
    string _active;
    vector<string> _options;
    Button *_opener;
    int _dropdown_rows;
    int _current;
    int _opened_height;

    void _opener_button_function();
public:
    Dropdown(int, int, int, vector<string>, int);
    virtual void draw() override;
    virtual bool is_dropdown_present(int, int);
    virtual void handle(genv::event) override;
    virtual void close();
    virtual void choose(int);
    virtual void scroll(bool);
    virtual string get_saveable();
};

#endif // DROPDOWNWIDGET_HPP_INCLUDED
