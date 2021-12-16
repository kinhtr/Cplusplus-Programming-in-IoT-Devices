#include "OverflowCounter.h"
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
		Notify();
	}
	else {
		initial--;
	}
}

OverflowCounter::operator int(){
	return initial;
}

void OverflowCounter::SetObserver(CounterObserver* obs0) {
	obs.push_back(obs0);
}

void OverflowCounter::Notify() {
	for (auto i : obs) { i->HandleLimitReached(this); }
}