#ifndef SUDOKUPART_HPP_INCLUDED
#define SUDOKUPART_HPP_INCLUDED

#include "basewidget.hpp"
#include "numericwidget.hpp"
#include <vector>

class SPart: public Widget{
protected:
    vector<Numeric *> _data;

public:
    SPart(int, int, int, int, vector<Numeric *>);
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual void check_data();

};

#endif // SUDOKUPART_HPP_INCLUDED
