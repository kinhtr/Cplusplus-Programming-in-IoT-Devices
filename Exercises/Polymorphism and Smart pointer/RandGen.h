	#pragma once
#include <vector>
#include <time.h>
#include <iostream>
class RandGen {
public:
	RandGen(int lower0, int upper0) : upper(upper0), lower(lower0) { srand(time(NULL)); }
	std::shared_ptr<Point> operator()();
private:
	const int lower;
	const int upper;
};