#include "OverflowCounter.h"
#include <iostream>
void OverflowCounter::inc() {
	if (initial == limit) {
		initial = 0;
		Notify();
	}
	else {
		initial++;
	}
}

void OverflowCounter::dec() {
	if (initial == 0) {
		initial = limit;
		//Notify();
	}
	else {
		initial--;
	}
}

OverflowCounter::operator int() {
	return initial;
}

void OverflowCounter::SetObserver(Observer* o) {
	obs = o;
}

void OverflowCounter::Notify() {
	obs->HandleLimitReached();
}

void OverflowCounter::test() {
	std::cout << "s";
}