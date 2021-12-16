#include <iostream>
#include "CounterUser.h"

CounterUser::CounterUser(int limit) {
	ofc = OverflowCounter(0, limit);
	ofc.SetObserver(this);
}

void CounterUser::HandleLimitReached() {
	std::cout << "Limit has been reached" << std::endl;
}

void CounterUser::IncrementBy(int n) {
	for (int i = 0; i < n; ++i) {
		ofc.inc();
	}
}
