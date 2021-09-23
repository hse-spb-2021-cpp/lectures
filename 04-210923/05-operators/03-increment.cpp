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

    bigint operator+(const bigint &other) const {
        return bigint(*this) += other;
    }
    
    bigint &operator+=(const bigint &other) {
        return *this = *this + other;
    }
};

int main() {
    bigint a = 4;
    bigint &b = a += 2;
    bigint c = 1;
    c += a += 2;
}
