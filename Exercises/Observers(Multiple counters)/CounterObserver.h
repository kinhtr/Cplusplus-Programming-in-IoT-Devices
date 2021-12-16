#pragma once
#include "Couter.h"
class CounterObserver {
public:
	virtual void HandleLimitReached(Counter* ctr) = 0;
};

class LimitedObserver : public CounterObserver {
	void HandleLimitReached(Counter* ctr);
};

class OverflowObserver : public CounterObserver {
	void HandleLimitReached(Counter* ctr);
};