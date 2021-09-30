#include <iostream>

struct Foo {
    void foo() {
        bar();
    }

    void bar() {
        foo();
    }

    struct Bar {
    };
};

int main() {
    Foo::Bar b;
}
