#pragma once

class CounterObserver;
class Counter {
public:
	virtual void inc() = 0;
	virtual void dec() = 0;
	virtual void SetObserver(CounterObserver*) = 0;
	virtual operator int() = 0;
	virtual ~Counter() {};
};
