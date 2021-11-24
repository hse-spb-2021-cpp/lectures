#include <iostream>

struct Foo {
    char c = 0;
    int i = 0;
};

struct Bar {
    char c = 0;
    int i = 0;
};

int main() {
    std::cout << sizeof(Foo) << "\n";
    Foo f;
    std::cout << static_cast<void*>(&f.c) << "\n";
    std::cout << &f.i << "\n";

    std::cout << sizeof(Bar) << "\n";
    Bar b;
    std::cout << &b.i << "\n";
    std::cout << static_cast<void*>(&b.c) << "\n";
}
