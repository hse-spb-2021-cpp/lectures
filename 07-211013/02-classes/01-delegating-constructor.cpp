#include <string>
#include <vector>

struct bigint {
    std::vector<int> digits;

    bigint(int x) : digits{x % 10, x / 10} {
    }

    bigint() : bigint(0) {}
};

int main() {
}
