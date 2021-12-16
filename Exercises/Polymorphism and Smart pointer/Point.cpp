#include <iostream>
#include "Point.h"


void Point::input(const char* prompt) {
    std::cout << prompt << std::endl;
    std::cout << "Enter x:";
    std::cin >> x;
    std::cout << "Enter y:";
    std::cin >> y;
}

void Point::output() const {
    std::cout << "Coordinates: (" << x << "," << y << ")" << std::endl;
}
 
double Point::area() const {
    return 0.0;
}

void Point::move(double deltax, double deltay) {
    x += deltax;
    y += deltay;
}