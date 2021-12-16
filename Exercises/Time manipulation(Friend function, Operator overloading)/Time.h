#pragma once
#include <string> 
#include <iostream>

class Time {
	friend std::ostream& operator<<(std::ostream& out, const Time& t);
	friend std::istream& operator>>(std::istream& in, Time& t);
private:
	int hour;
	int min;
public:
	Time(int hour = 0, int min = 0);
	void read(const char* str);
	bool lessThan(Time t2);
	Time subtract(Time t2);
	void display();
	bool operator<(const Time& t2);
	Time operator-(Time t2);
	Time operator+(Time t2);
	Time operator++();
	Time operator++(int);
	bool operator>(const Time& t2);
	bool operator==(const Time& t2);
};