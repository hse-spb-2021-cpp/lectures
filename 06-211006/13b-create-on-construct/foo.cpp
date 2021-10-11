#include <iostream>

struct Foo {
    Foo() {
        std::cout << "Foo()\n";
    }
};

Foo &create_f() {
    std::cout << "before 'static Foo f'\n";
    static Foo f;
    std::cout << "after 'static Foo f'\n";
    return f;
}
