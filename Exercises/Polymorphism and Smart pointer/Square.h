#pragma once
#include "Point.h"
//definition of class Circle
class Square : public Point {
public:
    //constructor
    Square(double xcoord = 0.0, double ycoord = 0.0, double height = 0.0, double width = 0.0);
    // destructor
    virtual ~Square() = default;
    void input(const char* prompt) override;
    void output() const override;
    double area() const override;
private:
    double height;
    double width;
};