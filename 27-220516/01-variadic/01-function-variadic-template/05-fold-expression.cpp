#include <iostream>

// Since C++17: https://en.cppreference.com/w/cpp/language/fold
// Fold expression should always be inside its own parenthesis.

template<typename ...Ts>
auto sum1(const Ts &...vs) {
    return (vs + ...);  // unary right fold: v0 + (v1 + (v2 + ...))
}

template<typename ...Ts>
auto sum2(const Ts &...vs) {
    return (vs + ... + 0);  // binary right fold: v0 + (v1 + (v2 + 0))
}

template<typename ...Ts>
auto sum_twice(const Ts &...vs) {
    return ((vs * 2) + ... + 0);  // patterns are allowed
}

template<typename ...Ts>
void print(const Ts &...vs) {
    // binary left fold: (std::cout << v0) << v1
    (std::cout << ... << vs) << "\n";
}

int main() {
    // std::cout << sum1() << "\n";  // compilation error
    std::cout << sum1(1, 2, 3) << "\n";
    std::cout << sum1("hello", " ", std::string("world")) << "\n";

    std::cout << sum2() << "\n";
    std::cout << sum2(1, 2, 3) << "\n";

    std::cout << sum_twice(1, 2, 3) << "\n";

    print(1, "hello");
}
