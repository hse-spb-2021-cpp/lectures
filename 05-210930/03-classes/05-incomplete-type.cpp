#include <iostream>
// https://en.cppreference.com/w/cpp/language/type
struct Bar;

struct Foo {
    Bar *b;
    std::vector<Bar> bs;
};

struct Bar {
    Foo f;
};

int main() {
}
