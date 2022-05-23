#include <iostream>

struct my_pair {
    int a, b;
    constexpr int sum() const { return a + b; }
};
static_assert(my_pair{1, 2}.sum() == 3);

struct my_pair_2 {
    int a, b;
    my_pair_2() {
        std::cin >> a >> b;
    }
    constexpr my_pair_2(int a_, int b_) : a(a_), b(b_) {}  // both run-time and compile-time
    constexpr int sum() const { return a + b; }
};
static_assert(my_pair_2{1, 2}.sum() == 3);

int main() {
    my_pair_2 x;
    std::cout << x.sum() << "\n";
}
