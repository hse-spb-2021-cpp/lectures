#include <vector>
#include <iostream>

struct bigint {
    std::vector<int> digits;
    int var;

    bigint(int x) : digits{x % 10, x / 10} {
        std::cout << this << " bigint(" << x << ")\n";
    }

    bigint() : bigint(0)/*, var(10)*/ {  // since C++11
        var = 10;
        std::cout << this << " bigint()\n";
    }

    bigint(bool) {
        std::cout << this << " bigint(bool)\n";
        bigint(0);
        std::cout << this << " digits.size() == " << digits.size() << "\n";
    }
};

int main() {
    [[maybe_unused]] bigint b1;
    [[maybe_unused]] bigint b2(true);
}
