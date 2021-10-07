#include <iostream>

struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }
};

Foo f;
