#pragma once
#include "Point.h"
//definition of class Circle
class Circle : public Point {
public:
    //constructor
    Circle(double xcoord = 0.0, double ycoord = 0.0, double radius0 = 0.0);
    // destructor
    virtual ~Circle() = default;
    void input(const char* prompt) override;
    void output() const override;
    double area() const override;
private:
    double radius;
};