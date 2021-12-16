#include <iostream>
#include "Circle.h"

Circle::Circle(double xcoord, double ycoord, double radius0) : Point(xcoord, ycoord) {
	radius = radius0;
}

void Circle::input(const char* prompt) {
	Point::input(prompt);
	std::cout << "Enter radius:";
	std::cin >> radius;
}
void Circle::output() const {
	std::cout << "Circle's area: " << area() << " ";
	Point::output();
}
double Circle::area() const {
	const float pi = 3.14159f;
	return pi * radius * radius;
}