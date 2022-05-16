#include <iostream>

// https://foonathan.net/2020/05/fold-tricks/

template<typename ...Ts>
void println(const Ts &...vs) {
    bool first = true;
    auto f = [&](const auto &v) {  // In C++11: use a templated class.
        if (first) {
            first = false;
        } else {
            std::cout << " ";
        }
        std::cout << v;
    };
    (f(vs), ...);  // C++17. Use array initialization for C++14 and before.
    std::cout << "\n";
}

int main() {
    println(12, "hello", "world");
}
