#include <cassert>
#include <iostream>
#include <vector>

struct bigint {
private:
    std::vector<int> digits;

public:
    bigint() {}
    bigint(int digit) : digits{digit} {
        assert(0 <= digit && digit < 10);
    }

    bigint &operator++() {
        return *this;
    }

    bigint operator++(int) {
    }
};

int main() {
    bigint a = 4;
    ++a;  // a.operator++()
    a++;  // a.operator++(0)
}
