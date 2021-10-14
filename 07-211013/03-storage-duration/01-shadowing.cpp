#include <cassert>
#include <iostream>

struct Foo {
    int x;
    Foo(int x) : x(x + 1) {
        std::cout << "x=" << x << "\n";
        std::cout << "this->x=" << this->x << "\n";
    }
};

int main() {
    [[maybe_unused]] Foo f(10);

    // int f = 20;  // error, same scope

    {
        // shadowing
        // -Wshadow
        int f = 30;
        assert(f == 30);
    }

    for (int i = 0; i < 3; i++) {
       std::cout << "i = " << i << "\n";
       // shadowing
       // -Wshadow
       for (int i = 0; i < 3; i++) {
           std::cout << "    i = " << i << "\n";
       }
       std::cout << "i = " << i << "\n";
    }
}
