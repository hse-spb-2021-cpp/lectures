#include <cassert>
#include <iostream>
#include <vector>

struct bigint {
    std::vector<int> digits;
    int sign = 1;

    bigint() /*: digits{}*/ {
    }
    bigint(int value) : digits{value % 10, value / 10} {
        assert(value >= 0);
        assert(value < 100);
    }
};

int main() {
    bigint value(23);
    std::cout << value.digits[0] << "\n";
    std::cout << value.digits[1] << "\n";
}
