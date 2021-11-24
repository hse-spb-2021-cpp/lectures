#include <iostream>

struct Base {
    explicit Base(int) {
    }

private:
    explicit Base(int, int) {
    }
};

struct Derived : Base {
private:  // Does not affect constructors (OH GOD WHY), their access level is
          // the same as in Base.
    using Base::Base;

public:
    Derived(int x, int y)
        : Base(x, y) {  // Hides parent constructor, as with methods.
        std::cout << "Derived2\n";
    }
    Derived(int x, int y, int) : Base(x, y) {
        std::cout << "Derived3\n";
    }
};

int main() {
    [[maybe_unused]] Derived d1{10};
    [[maybe_unused]] Derived d2{10, 20};
    [[maybe_unused]] Derived d3{10, 20, 30};
}
