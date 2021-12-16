#include <iostream>
#include <vector>
#include "Circle.h"
#include "Square.h"
#include <algorithm>
#include "RandGen.h"
using namespace std;

int main() {
	std::vector<std::shared_ptr<Point>> v;
	v.push_back(make_shared<Point>(1.0, 1.0));
	v.push_back(make_shared<Circle>(2.0, 2.0, 2.0));
	v.push_back(make_shared<Square>(5.0, 5.0, 2.0, 2.0));
	auto tmp = make_shared<Point>();
	tmp->input("Point:");
	v.push_back(tmp);
	tmp = make_shared<Circle>();
	tmp->input("Circle:");
	v.push_back(tmp);
	tmp = make_shared<Square>();
	tmp->input("Square:");
	v.push_back(tmp);
	for (const auto& i : v) {
		i->output();
	}

	sort(v.begin(), v.end(), [](shared_ptr<Point> p1, shared_ptr<Point> p2) {
		return p1->area() < p2->area();
		});
	cout << "Sorted:" << endl;
	for (const auto& i : v) {
		i->output();
	}
	//EXTRA
	vector<shared_ptr<Point>> v1(5);
	generate(v1.begin(), v1.end(), RandGen(1, 3));
	for (const auto& i : v1) {
		i->output();
	}
	 //Smart pointer and raw pointer Test
	v1.push_back(make_shared<Point>(1,5));
	Point* p = new Circle(5, 2, 3);
	v1[5] = make_shared<Circle>(1, 2, 9); // cannot point to new Circle(1,2,9)
	p->output();
	v1[5]->output();	
	shared_ptr<Point> p1(new Circle(10, 2, 3)); // create a copy work
	//p1 = new Circle(10,2,3));// p1 = new Circle(10,2,3) assignment does not work	
	p1->output();
	return 0;
}
