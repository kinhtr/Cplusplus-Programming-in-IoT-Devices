#pragma once
#include "Couter.h"
#include "Observer.h"

class OverflowCounter : public Counter {
public:
	OverflowCounter(int initial0 = 0, int limit0 = 0) :initial(initial0), limit(limit0), obs(nullptr) {}
	void inc();
	void dec();
	operator int();
	void  SetObserver(Observer*o);
	virtual ~OverflowCounter() {};
	void test();
private:
	int initial;
	int limit;
	Observer* obs;
	void Notify();
};

