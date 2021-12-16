#pragma once
#include <vector>
#include <string>
#include "Time.h"
using namespace std;

class Day {
private:
    int day;
    string month;
    vector<Time> list;
public:
    Day();
    bool from_str(const string& s);
    string to_str();
    void dst(int offset);
    void erase();
};