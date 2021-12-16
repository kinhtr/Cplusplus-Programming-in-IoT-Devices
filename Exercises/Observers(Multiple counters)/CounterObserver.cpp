#include "CounterObserver.h"
#include <iostream>

void LimitedObserver::HandleLimitReached(Counter* c) {
	std::cout << "Counter reached the limit" << std::endl;
	std::cout << "Current value: " << * c << std::endl;
}

void OverflowObserver::HandleLimitReached(Counter* c) {
	std::cout << "Overflow has occured" << std::endl;
	std::cout << "Current value: " << * c << std::endl;
}