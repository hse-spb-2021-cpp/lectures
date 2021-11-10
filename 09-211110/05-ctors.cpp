#include <cassert>

struct Base {
    int x;
    Base(int x_) : x(x_) {}
};

struct Derived : Base {
    int y = 20;

    Derived() : Base(10) {}
//    Derived(int y_) : y(y_), Base(10) {}  // -Wreorder
    Derived(int y_) : Base(10), y(y_) {}  // -Wreorder
};

struct DerivedNaive : Base {
};

int main() {
    Derived d;
    assert(d.x == 10);
    // DerivedNaive dn(10);  // Конструкторы не наследуются.
    // operator=, конструкторы копирования/перемещения генерируются заново (если можно).
}
