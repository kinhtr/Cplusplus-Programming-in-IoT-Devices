# include "LimitedCouter.h"

void LimitedCounter::inc() {
	if (initial < limit) {
		initial++;
	}
	else {
		Notify();
	}
}

void LimitedCounter::dec() {
	if (initial > 0) {
		initial--;
	}
	else {
		Notify();
	}
}

LimitedCounter::operator int() {
	return initial;
}

void LimitedCounter::SetObserver(CounterObserver* o) {
	obs.push_back(o);
}

void LimitedCounter::Notify() {
	for (auto i : obs) { i->HandleLimitReached(this); }
}