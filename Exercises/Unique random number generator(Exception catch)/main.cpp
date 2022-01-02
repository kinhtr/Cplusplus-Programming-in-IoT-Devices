#include <iostream>
#include <vector>
#include <algorithm>

class UniqueRng {
public:
    UniqueRng(int lower0, int upper0) : max(upper0), min(lower0), numbers() { srand(time(NULL)); }
    int operator()();
    const int getMax() const;
    const int getMin() const;
private:
    const int min;
    const int max;
    std::vector<int> numbers;
};

int UniqueRng::operator()() {
    int number;
    do {
        number = max - rand() % (max - min + 1);
    } while (find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

const int UniqueRng::getMax() const {
    return max;
}
const int UniqueRng::getMin() const {
    return min;
}

void test_generator(UniqueRng ur, int count);

int main(void) {
    UniqueRng randGen(5, 13);

    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}

void test_generator(UniqueRng ur, int count) {
    bool err(false);
    int size = ur.getMax() - ur.getMin() + 1;
    std::vector<int> v;
    std::cout << "Generating numbers:\n";
    try {
        if (count > size) {
            err = true;
            throw std::runtime_error("Unable to produce unique random number");
        }
        v.resize(count);
    } catch (std::runtime_error& e) {
        v.resize(size);
        std::cout << "Exception: " << e.what() << std::endl;
    }
    generate(v.begin(), v.end(), ur);
    if (err) { 
        std::cout << "Tried to generate " << count << ". Got only " << size << std::endl;
    }

    for (const auto& i : v) { std::cout << i << std::endl; }
    std::cout << "End of generator\n" << std::endl;
}
