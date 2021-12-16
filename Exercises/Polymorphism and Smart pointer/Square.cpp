#include <iostream>
#include "Square.h"

Square::Square(double xcoord, double ycoord, double h, double w) : Point(xcoord, ycoord) {
	height = h;
	width = w;
}

void Square::input(const char* prompt) {
	Point::input(prompt);
	std::cout << "Enter height: ";
	std::cin >> height;
	std::cout << "Enter width: ";
	std::cin >> width;
}

void Square::output() const {
	std::cout << "Square's area: " << area() << " ";
	Point::output();
}

double Square::area() const {
	return height * width;
}