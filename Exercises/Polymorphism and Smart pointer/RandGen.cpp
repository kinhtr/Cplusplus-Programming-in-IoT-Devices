#include "Square.h"
#include "Circle.h"
#include "RandGen.h"
#include <iostream>

std::shared_ptr<Point> RandGen::operator()(){
	std::shared_ptr<Point> p;
	int n = upper - rand() % (upper - lower + 1);
	if (n == 1) {
		p = std::make_shared<Point>();
		p->input("Point:");
	}
	else if (n == 2) {
		p = std::make_shared<Circle>();
		p->input("Circle:");
	}
	else {
		p = std::make_shared<Square>();
		p->input("Square:");
	}
	return p;
}