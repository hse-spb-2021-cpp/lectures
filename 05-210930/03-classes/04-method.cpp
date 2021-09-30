#include <iostream>

struct Foo {
    int field;  // always inside struct Foo.

    void foo(int n);  // declaration
};

void Foo::foo(int n) {  // definition
    std::cout << "called foo(" << n << ")\n";
}

int main() {
   Foo f;
   f.foo(10);
}
