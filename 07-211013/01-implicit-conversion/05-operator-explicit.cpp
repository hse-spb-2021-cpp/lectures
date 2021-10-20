#include <iostream>

struct Foo {
    explicit operator int() {
        return 10;
    }
};

struct Bar {
    explicit operator bool() {
        return true;
    }
};

int main() {
    [[maybe_unused]] Foo f;
    [[maybe_unused]] Bar b;
    // [[maybe_unused]] bool x1 = f;
    // [[maybe_unused]] bool x2 = b;

    // if (f) {}  // no implicit conversion to int or bool
    if (b) {}  // explicit conversion to bool!

    // for (; f;) {}
    for (; b;) {}

    // while (f) {}
    while (b) {}

    // [[maybe_unused]] int x3 = 10 + f;
    // [[maybe_unused]] int x4 = 10 + b;
}
