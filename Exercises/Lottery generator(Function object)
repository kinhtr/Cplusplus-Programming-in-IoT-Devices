#include <iostream>
#include <algorithm>
#include <vector>
#include <string>	
#include <iterator>
using namespace std;

class RandGen {
public:
	RandGen(int lower0, int upper0) : upper(upper0), lower(lower0), numbers() { srand(time(NULL)); }
	int operator()();
private:
	const int lower;
	const int upper;
	vector<int> numbers;
};

void lotto_generator(vector<int>& v, RandGen& r);

int main(void) {
	string input;
	vector<int> lotto(7);
	vector<int> viking(6);
	vector<int> ejackpot(5);
	while (input != "no") {
		cout << "Do u wanna generate lottery numbers('yes' to proceed 'no' to quit)?";
		cin >> input;
		if (input == "yes") {
			vector<int> comp, comp2;
			RandGen rand1(1, 40);
			RandGen rand2(1, 48);
			RandGen rand3(1, 50);
			int index = 1;
			lotto_generator(lotto, rand1);
			lotto_generator(viking, rand2);
			set_intersection(lotto.begin(), lotto.end(), viking.begin(), viking.end(), back_inserter(comp));
			if (comp.size() > 0) {
				cout << "Matching numbers:" << endl;
				for_each(comp.begin(), comp.end(), [&index](int i) {
					cout << "#" << index++ << ":" << i << endl;
					});
			}
			lotto_generator(ejackpot, rand3);
			set_intersection(ejackpot.begin(), ejackpot.end(), comp.begin(), comp.end(), back_inserter(comp2));
			if (comp2.size() > 0) {
				index = 1;
				cout << "Matching numbers in three sets:" << endl;
				for_each(comp2.begin(), comp2.end(), [&index](int i) {
					cout << "#" << index++ << ":" << i << endl;
					});
			}
		}
		else if (input == "no") {
			cout << "Quitting the program..";
		}
		else {
			cout << "Wrong input try again!" << endl;
		}
	} 
}
int RandGen::operator()() {
	int number;
	do {
		number = upper - rand() % (upper - lower + 1);
	} while (find(numbers.begin(), numbers.end(), number) != numbers.end());
	numbers.push_back(number);
	return number;
}

void lotto_generator(vector<int>& v, RandGen &r) {
	string lottoType; 
	if (v.size() == 7) {
		lottoType = "Lotto";
	}
	else if (v.size() == 6) {
		lottoType = "Viking lotto";
	}
	else {
		lottoType = "Eurojackpot";
	}
	ostream_iterator<int> it(cout << lottoType + ": ", " ");
	generate(v.begin(), v.end(), r);
	copy(v.begin(), v.end(), it);
	cout << endl;
	sort(v.begin(), v.end());
}
