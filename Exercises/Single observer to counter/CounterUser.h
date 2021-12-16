#pragma once
#include "OverflowCounter.h"
#include "Observer.h"

class CounterUser : public Observer{
public:
	CounterUser(int limit);
	void IncrementBy(int n);
	void HandleLimitReached();

private:
	OverflowCounter ofc;
};	