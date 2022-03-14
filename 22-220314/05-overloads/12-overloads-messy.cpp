#include <iostream>

void foo(const int&) {
    std::cout << "1\n";
}

void foo(char) {
    std::cout << "2\n";
}

template<typename T>
void foo(T) {
    std::cout << "3\n";
}

template<typename T>
void foo(T&) {
    std::cout << "4\n";
}

int main() {
    // Compilation error: all are ambiguous. I have little idea why.
    [[maybe_unused]] int y = 10;
    foo<>(y);
    foo(y);

    [[maybe_unused]] double z = 10.3;
    foo<>(z);
    foo(z);
}
