#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <chrono>
#include <thread>
#include <mutex>

class Dealer;
class Car {
	friend std::ostream &operator<<(std::ostream &out, const Car &car);
public:
	Car(const char* m="Ford", const char *l=nullptr, int ml=0) : model(m), license(l ? l : (rand() % 2 ? "FOO-" : "BAR-") + std::to_string(rand() % 999 + 1)), mileage(ml ? ml : rand() % 10000) {}
	~Car() { std::cout << model << " " << license << " deleted" << std::endl; };
	void Read();
	void setDealer(std::shared_ptr<Dealer> dealer) { d = dealer; }
	std::string GetLicense() const { return license; }
private:
	std::string model;
	std::string license;
	int mileage;
	std::weak_ptr<Dealer> d;
}; 

void Car::Read()
{
	//std::cout << "Enter car information" << std::endl;
	// replace the following with your own code
	model = "Seat";
	license = (rand() % 2 ? "ZAP-" : "ZIP-") + std::to_string(rand() % 999 + 1);
	mileage = 10000 + rand() % 10000;
}


/* ---------------------- */

class Website {
public:
	Website(const char *n = nullptr) : name(n ? n : "www.cars" + std::to_string(rand() % 99 + 1) + ".com") {}
	~Website() { std::cout << name << " deleted" << std::endl; };
	void advertise(std::weak_ptr<Car> car) { listing.push_back(car); }
	void print(std::ostream& out = std::cout);
	void run() { if (listing.size() != 0) {
		for (int i = 0; i < 10; i++) std::this_thread::sleep_for(std::chrono::seconds(1)); print();
		}
	}
private:
	std::vector<std::weak_ptr<Car>> listing;  
	std::string name;
	static std::mutex m;
};

std::mutex Website::m; //static mutex definition

class Dealer : public std::enable_shared_from_this<Dealer>{
	friend std::ostream &operator<<(std::ostream &out, const Dealer &dealer);
public:
	Dealer(const char *name_ = "John Doe") : name(name_) {};
	~Dealer() { std::cout << name << " deleted" << std::endl; };
	void buy();
	void sell();
	void add(std::shared_ptr<Car> car) { cars.push_back(car); for (auto site : sites) site->advertise(car);
	car->setDealer(shared_from_this()); }
	void add_site(std::shared_ptr<Website> w) { sites.push_back(w); }
	const std::string getName() const { return name; }
private:
	std::string name;
	std::vector<std::shared_ptr<Car>> cars;
	std::vector<std::shared_ptr<Website>> sites;
};



std::ostream& operator<<(std::ostream& out, const Car& car)
{
	std::string d_name;
	auto sp = car.d.lock();
	if (sp) { d_name = sp->getName(); }
	std::cout << "Model: " << car.model << std::endl << "License: " << car.license << std::endl 
		<< "Mileage: " << car.mileage << "(Dealer: " << d_name << ")" << std::endl;

	return out;
}

void Website::print(std::ostream& out) {
	std::lock_guard<std::mutex> lg(m);
	out << name << std::endl;
	for (auto car : listing) {
		auto sp = car.lock();
		if (sp) {
			out << *sp;
		}
	}
	out << name << " end of list" << std::endl;
}

void Dealer::buy()
{
	auto car = std::make_shared<Car>();
	car->Read();
	add(car);
}



std::ostream & operator<<(std::ostream & out, const Dealer & dealer)
{
	std::cout << dealer.name << "'s cars for sale" << std::endl;
	for (auto car : dealer.cars) std::cout << *car;
	std::cout << "End of " << dealer.name << "'s cars listing" << std::endl;

	return out;
}

void Dealer::sell()
{
	std::cout << *this; // print my list of cars
	std::cout << "Enter license of car you want to buy" << std::endl;

	std::string license;
	std::cin >> license;
	auto ci = std::find_if(cars.begin(), cars.end(), [&license](std::shared_ptr<Car> c) {return license == c->GetLicense(); });
	if (ci != cars.end()) {
		cars.erase(ci);
	}
}

/* ---------------------- */


void webThread(std::shared_ptr<Website> w) {
	w->run();
}
void car_sales()
{
	std::string input("");
	std::cout << "Car sales started" << std::endl;
	auto wa = std::make_shared<Website>("www.autos.com");
	auto wb = std::make_shared<Website>("www.bilar.com");
	auto wc = std::make_shared<Website>("www.cars.com");
	auto a = std::make_shared<Dealer>("Alan Aldis");
	auto b = std::make_shared<Dealer>("Bill Munny");
	
	auto c = std::make_shared<Dealer>("Casey Ball");
	auto ca = std::make_shared<Car>("ca", "ce",1500);
	auto cb = std::make_shared<Car>("ss", "ee", 2500);

	a->add_site(wa);
	a->add_site(wb);
	b->add_site(wb);
	b->add_site(wc);
	c->add_site(wa);
	c->add_site(wb);
	c->add_site(wc);

	a->buy();
	a->buy();
	a->buy();
	a->buy();

	b->buy();
	b->buy();
	b->buy();

	c->buy();
	c->buy();
	c->add(ca);
	ca = nullptr;
	c->add(cb);
	cb = nullptr;
	std::thread t1(webThread, wa), t2(webThread, wb), t3(webThread, wc);
		/*
		wa->print();
		wb->print();
		wc->print();

		std::cout << *a << *b << *c << std::endl;

		a->sell();

		std::cout << *a << *b << *c << std::endl;

		wa->print();
		wb->print();
		wc->print();*/
	
	while (input != "quit") {
		std::cout << "Select the agent you want to buy car from (type quit to exit):" << std::endl;
		std::cout << "(a) Alan Aldis\n(b) Bill Munny\n(c) Casey Ball" << std::endl;
		std::cin >> input;
		if (input == "a") {
			a->sell();
		}
		else if (input == "b") {
			b->sell();
		}
		else if (input == "c") {
			c->sell();
		}
		else if (input == "quit") {
			std::cout << "Exitting the programm..." << std::endl;
		}
		else {
			std::cout << "Wrong input!" << std::endl;
		}
	}
	//wa->print();
	//wb->print();
	//wc->print();

	t1.join();
	t2.join();
	t3.join();
	std::cout << "Car sales ended" << std::endl;
}

int main(int argc, char **argv) {
	_CrtMemState s1;
	_CrtMemCheckpoint(&s1);

	srand(time(NULL));

	car_sales();

	_CrtMemState s2,s3;
	_CrtMemCheckpoint(&s2);
	if (_CrtMemDifference(&s3, &s1, &s2)) {
		_CrtDumpMemoryLeaks();
		_CrtMemDumpStatistics(&s3);
	}

	return 0;
}
