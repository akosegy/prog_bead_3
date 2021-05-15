#ifndef SUDOKUPART_HPP_INCLUDED
#define SUDOKUPART_HPP_INCLUDED

#include "basewidget.hpp"
#include "numericwidget.hpp"
#include <vector>

using namespace std;

class SPart: public Widget{
protected:
    vector<Numeric *> _data;

public:
    SPart(int, int, int, int, vector<Numeric *>);
    virtual ~SPart();
    virtual void draw() override;
    virtual void handle(genv::event) override;
    virtual vector<Numeric *> check_data();

};

#endif // SUDOKUPART_HPP_INCLUDED
