#include <iostream>
#include "CounterObserver.h"
#include "LimitedCouter.h"
#include "OverflowCounter.h"

int main() {
	LimitedCounter l(0, 5);
	OverflowCounter o(0, 5);
	LimitedObserver lo;
	OverflowObserver oo;
	LimitedObserver lo2; 
	l.SetObserver(&lo);
	l.SetObserver(&lo2);
	o.SetObserver(&oo);
	o.SetObserver(&lo2);
	for (int i = 0; i < 6; ++i) { 
		l.inc(); 
		o.inc(); 
	}
	//o.dec();
	//l.inc();
}