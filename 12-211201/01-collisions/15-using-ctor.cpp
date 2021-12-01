#include <iostream>

struct Base {
    explicit Base(int) {
    }

private:
    explicit Base(int, int) {  // Cannot be used in derived classes.
    }
};

struct Derived : Base {
private:  // Does not affect constructors (OH GOD WHY), their access level is
          // the same as in Base.
    using Base::Base;
    // Base(int, int) is not added: it's private to Base.
    // Base(int) is added and is still public.

public:
    Derived(int x, int)
        : Base(x) {  // Hides parent constructor, as with methods.
        std::cout << "Derived2\n";
    }
    Derived(int x, int, int) : Base(x) {  // Still unable to call Base(int, int)
        std::cout << "Derived3\n";
    }
};

int main() {
    [[maybe_unused]] Derived d1{10};
    [[maybe_unused]] Derived d2a{10, 20};
    [[maybe_unused]] Derived d2b = {10, 20};
    [[maybe_unused]] Derived d3 = {10, 20, 30};
}
