#include <iostream>

struct Base {
    explicit Base(int) {
    }
    explicit Base(int, int) {
    }
};

struct Derived : Base {
    using Base::Base;

    Derived(int x, int) : Base(x) {  // Hides parent constructor, as with methods.
        std::cout << "Derived2\n";
    }
    Derived(int x, int, int) : Base(x) {  // Should specify Base() ctor explicitly unless it's the default.
        std::cout << "Derived3\n";
    }
};

int main() {
    [[maybe_unused]] Derived d1{10};
    [[maybe_unused]] Derived d2a{10, 20};
    [[maybe_unused]] Derived d2b = {10, 20};
    [[maybe_unused]] Derived d3 = {10, 20, 30};
}
