#include "Time.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <fstream>
#pragma warning(disable : 4996)

#define H_MAX 24
#define M_MAX 60
using namespace std; 

Time::Time(int hour0, int min0) {
	hour = hour0; 
	min = min0;
}
void Time::read(const char* str) {
	bool invalid = true;
	string buffer;
	while (invalid) {
		cout << str;
		getline(cin, buffer);
		if (sscanf(buffer.c_str(), "%d:%d", &hour, &min) == 2 
			&& hour < H_MAX && min < M_MAX && hour >= 0 && min >= 0) {
			invalid = false;
		}
		else {
			cout << "Wrong format! Try again!" << endl;
		}
	}
}
bool Time::lessThan(Time t2) {
	if (hour < t2.hour) {
		return true;
	}
	else if (hour == t2.hour && min < t2.min) {
		return true;
	}
	else {
		return false;
	}
}
Time Time::subtract(Time t2) {
	Time duration;
	duration.hour = hour - t2.hour;
	duration.min = min - t2.min;
	if (duration.min < 0) {
		duration.min += M_MAX;
		duration.hour -= 1;
	}
	return duration;
}

void Time::display() {
	cout << setiosflags(ios::right); cout << setfill('0') << setw(2) << hour;
	cout << ":" << setfill('0') << setw(2) << min << endl;
}

ostream& operator<<(ostream& out, const Time& t) {
	out << setiosflags(ios::right); out << setfill('0') << setw(2) << t.hour;
	out << ":" << setfill('0') << setw(2) << t.min << endl;
	return out;
}

bool Time::operator<(const Time& t2) {
	if (hour < t2.hour) {
		return true;
	}
	else if (hour == t2.hour && min < t2.min) {
		return true;
	}
	else {
		return false;
	}
}

Time Time::operator-(Time t2) {
	Time duration;
	duration.hour = hour - t2.hour;
	duration.min = min - t2.min;
	if (duration.min < 0) {
		duration.min += M_MAX;
		duration.hour -= 1;
	}
	if (duration.hour < 0) {
		duration.hour += H_MAX;
	}
	return duration;
}

Time Time::operator+(Time t2) {
	Time sum;
	int overflow = 0;
	sum.min = min + t2.min;
	if (sum.min >= M_MAX) {
		sum.min -= M_MAX;
		overflow++;
	}
	sum.hour = hour + t2.hour + overflow;
	if (sum.hour >= H_MAX) {
		sum.hour -= H_MAX;
	}
	return sum;
}

Time Time::operator++() {
	min++;
	return *this;
}

Time Time::operator++(int) {
	Time old = *this;
	min++;
	return old;
}

istream& operator>>(istream& in, Time& t) { 
	bool invalid = true;
	string buffer;
	while (invalid) {
		getline(in, buffer);
		if (sscanf(buffer.c_str(), "%d:%d", &t.hour, &t.min) == 2
			&& t.hour < H_MAX && t.min < M_MAX && t.hour >= 0 && t.min >= 0) {
			invalid = false;
		}
		else {
			cout << "Wrong format! Try again!" << endl;
		}
	}
	return in;
}

bool Time::operator>(const Time& t2) {
	if (hour > t2.hour) {
		return true;
	}
	else if (hour == t2.hour && min > t2.min) {
		return true;
	}
	else {
		return false;
	}
} 

bool Time::operator==(const Time& t2) {
	if (hour == t2.hour && min == t2.min) {
		return true;
	}
	else {
		return false;
	}
}