#include "Day.h"
#include "Time.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#pragma warning(disable : 4996)
#define H_MAX 24

using namespace std;

Day::Day() : day(0), month("") {}

void Day::erase() {
	day = 0;
	month = "";
	list.clear();
}
bool Day::from_str(const string& s) {
	Time t;
	istringstream read(s);
	this->erase();
	if (read >> day) {
		if (read >> month) {
			if (read >> t) {
				list.push_back(t);
				while (read >> t) {
					list.push_back(t);
				}
				return true;
			}
		}
	}
	return false;
}


string Day::to_str() {
	ostringstream stream; 
	stream << day << " " << month << " ";
	sort(list.begin(), list.end());
	for (auto& t : list) {
		stream << setfill('0') << setw(2) << t.getHour() << ":";
		stream << setfill('0') << setw(2) << t.getMin() << " ";
	}
	return stream.str();
}

void Day::dst(int offset) {
	for (auto& t : list) {
		if (t.getHour() + offset >= H_MAX) {
			t.getHour() += offset - H_MAX;
		}
		else {
			t.getHour() += offset;
		}
	}
}

