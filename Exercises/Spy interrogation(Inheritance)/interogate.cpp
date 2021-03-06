#include <string>
#include <iostream>
using namespace std;

class Person {
public:
	Person(const char* name0 = "nobody");
	virtual ~Person() = default;
	virtual void identity() const;
	virtual void interrogate();
	const char* getName() const;
private:
	const char* name;
};

Person::Person(const char* name0) {
	name = name0;
}

void Person::identity() const {
	cout << name << endl;
}

void Person::interrogate(){}

const char* Person::getName() const {
	return name;
}
class Spy : public Person {
public:
	Spy(const char* name1, string alias = "Messi", int resistance = 1);
	void identity() const override;
	void interrogate() override;
	void set_identity(const char* alias);
private:
	string alias;
	int resistance;
};

Spy::Spy(const char* name1, string alias0, int resistance0): Person(name1) {
	alias = alias0;
	resistance = resistance0;
}
void Spy::identity() const {
	if (resistance > 0) {
		cout <<  "My name is " << alias << endl;
	}
	else {
		cout << "My alias is " << alias << ", my real name is " << getName() << endl;
	}
}

void Spy::interrogate() {
	--resistance;
}

void Spy::set_identity(const char* alias0) {
	alias = alias0;
}

int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	std::cout << std::endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		std::cout << "Who are you?" << std::endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}
