#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int mean(int* array, int n);
int main(void) {
	srand((unsigned int)time(NULL));
	int n{ 0 }, avg{ 0 };
	int* p;
	cout << "How many numbers you want to to have for the array?: " << endl;
	cin >> n;
	p = new int[n];
	for (int i = 0; i < n; i++) {
		p[i] = rand() % 100;
		cout << p[i] << endl;
	}
	avg = mean(p, n);
	cout << "The mean is " << avg << endl;
	delete[] p;
	return 0;
}

int mean(int* array, int n) {
	int sum(0);
	for (int i = 0; i < n; i++) {
		sum += array[i];
	}
	return sum / n;
}
