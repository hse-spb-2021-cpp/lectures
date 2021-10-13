#include <iostream>

struct Foo {
    // TODO: add example with operator int
    explicit operator bool() {
        return true;
    }
};

void bar([[maybe_unused]] int x) {
}

void baz(const Foo &) {
}

int main() {
    Foo f;
    // bool x = f;  // implicit

    if (f) {  // if (f.operator bool()) { // Explicit!
    } else {
    }

    while (f) {}
    for (; f;) {}

    // while (std::cin >> x) {}
    // while ((std::cin >> x).operator bool()) {}

    // In C++03 and before: safe bool idiom
    // const int z0 = std::cin;

    // [[maybe_unused]] int z1 = f;
    // [[maybe_unused]] int z2 = 10 + f;
    // bar(f);
}
