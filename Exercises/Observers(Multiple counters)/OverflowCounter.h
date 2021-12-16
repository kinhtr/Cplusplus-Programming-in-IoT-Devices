#pragma once
#include "Couter.h"
#include <vector>
#include "CounterObserver.h"

class OverflowCounter : public Counter {
public:
	OverflowCounter(int initial0, int limit0) :initial(initial0), limit(limit0) {}
	void inc();
	void dec();
	void SetObserver(CounterObserver* obs0);
	operator int();
	virtual ~OverflowCounter() {};
private:
	int initial;
	int limit;
	std::vector<CounterObserver*> obs;
	void Notify();
};