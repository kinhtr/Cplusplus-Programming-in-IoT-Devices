#pragma once
#include "Couter.h"
#include <iostream>
#include <vector>
#include "CounterObserver.h"

class LimitedCounter : public Counter {
public:
	LimitedCounter(int initial0, int limit0):initial(initial0), limit(limit0){}
	void inc();
	void dec();
	void SetObserver(CounterObserver* obs0);
	operator int();
	virtual ~LimitedCounter() {};
private:
	int initial;
	int limit;
	std::vector<CounterObserver*> obs;
	void Notify();
};