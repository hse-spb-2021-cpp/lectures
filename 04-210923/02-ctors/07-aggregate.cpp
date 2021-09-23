#include <iostream>

struct ratio {
    int num;
    int denom;
};

int main() {
    // aggregate initialization. Looks like an automatically generated constructor
    [[maybe_unused]] ratio r1{};
    [[maybe_unused]] ratio r2{3};  // num = 3, warning about missing 'denom' initializer
    [[maybe_unused]] ratio r3{3, 4};  // num = 3, denom = 4
}
