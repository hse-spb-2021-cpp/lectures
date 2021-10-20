#include <iostream>

struct Foo {
    operator int() {
        return 10;
    }
};

struct Bar {
    operator bool() {
        return true;
    }
};

int main() {
    [[maybe_unused]] Foo f;
    [[maybe_unused]] Bar b;
    [[maybe_unused]] bool x1 = f;  // implicit: user-defined + int-to-bool
    [[maybe_unused]] bool x2 = b;  // implicit: user-defined

    if (f) {}
    if (b) {}

    for (; f;) {}
    for (; b;) {}

    while (f) {}
    while (b) {}

    [[maybe_unused]] int x3 = 10 + f;
    [[maybe_unused]] int x4 = 10 + b;
}
