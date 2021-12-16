#include <iostream>
#include <string>
#include "Time.h"
#include <vector>
#include <algorithm>
using namespace std;

void print(const vector<Time> &v) 
{
	for(auto &t : v) {
		cout << t << endl;
	}
}

int main() {
	Time time1, time2, duration;

	cout << "Enter time 1: ";
	cin >> time1;
	cout << "Enter time 2: ";
	cin >> time2;
	if (time1<time2) {
		duration = time2 - time1;
		cout << "Starting time was " << time1 << endl;
	} else {
		duration = time1 - time2;
		cout << "Starting time was " << time2 << endl;
	}
	cout << "Duration was " << duration << endl;

	vector<Time> tv(5); 
	for(auto &t : tv) {
		cout << "Enter time: ";
		cin >> t;
	}

	cout << "Times: " << endl;
	print(tv);
	
	Time sum;
	for(auto t : tv) {
		sum = sum + t;
	}
	
	cout << "Sum of times: " << sum << endl;
	
	cout << "Post-increment: " << endl;
	print(tv);
	for(auto &t : tv) {
		cout << t++ << endl;
	}
	
	print(tv);

	cout << "Pre-increment: " << endl;
	for(auto &t : tv) {
		cout << ++t << endl;
	}

	sort(tv.begin(), tv.end());

	cout << "Sorted times: " << endl;
	print(tv);

	return 0;
}

