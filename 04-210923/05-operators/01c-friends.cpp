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

    // private, public, does not matter
    friend bool operator==(const bigint &a, const bigint &b);
};

bool operator==(const bigint &a, const bigint &b) {
    return a.digits == b.digits;
}

int main() {
    bigint a = 4, b = 5;
    std::cout << (a == b) << "\n";
    std::cout << (a == 6) << "\n";
    std::cout << (a == 4) << "\n";
    std::cout << (4 == b) << "\n";
    std::cout << (5 == b) << "\n";
    // a.digits = {0, 0, 0, 0};
}
