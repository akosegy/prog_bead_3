#ifndef TEXTINWIDGET_HPP_INCLUDED
#define TEXTINWIDGET_HPP_INCLUDED

#include "basewidget.hpp"

using namespace std;

class Text : public Widget {
protected:
    string _text;
    bool _is_input;

public:
    Text(int, int, int, int, string, bool);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual string get_text();
    virtual void set_text(string);
};

#endif // TEXTINWIDGET_HPP_INCLUDED
