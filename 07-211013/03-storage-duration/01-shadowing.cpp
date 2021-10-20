#include <cassert>
#include <iostream>

struct Foo {
    int x;
    Foo(int x) : x(x + 1) {
        std::cout << "x=" << x << "\n";
        std::cout << "this->x=" << this->x << "\n";
    }
};

int i = 100;

int main() {
    [[maybe_unused]] Foo f(10);

    // int f = 20;  // error, same scope

    {
        std::cout << f.x << "\n";
        // shadowing
        // -Wshadow
        int f = 30;
        assert(f == 30);
    }
    std::cout << f.x << "\n";

    for (int i = 0; i < 3; i++) {
       std::cout << "i = " << i << "\n";
       // shadowing
       // -Wshadow
       for (int i = 0; i < 3; i++) {
           std::cout << "    i = " << i << "\n";
           assert(::i == 100);  // can access global variables, but not nonlocal
       }
       std::cout << "i = " << i << "\n";
    }
}
