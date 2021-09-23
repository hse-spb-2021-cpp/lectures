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

    bool operator==(const bigint &other) const {
        return digits == other.digits;
    }
};

int main() {
    bigint a = 4, b = 5;
    std::cout << (a == b) << "\n";
    std::cout << (a == 6) << "\n";
    std::cout << (a == 4) << "\n";
    std::cout << (4 == b) << "\n";
}
