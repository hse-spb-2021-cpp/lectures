#include <string>
#include <iostream>

/*
   Base
   ^  ^
  /    \
 /      \
X        Y
^        ^
 \      /
  \    /
 Derived
*/

struct Base {
    int base_data = 0;
    // virtual ~Base() {}
};
struct X : virtual Base { int x_data = 0; };
struct Y : virtual Base { int y_data = 0; };
struct Derived : X, Y { };

int main() {
    Derived d1;
    X &x1 = d1;
    Base &b1 = d1;

    X x2;
    Base &b2 = x2;

    std::cout << &d1 << "\n";
    std::cout << &x1 << " " << &b1 << "\n";  // One offset
    std::cout << &x2 << " " << &b2 << "\n";  // Another offset

    // Downcast from a virtual base is not static:
    // static_cast<X&>(b1);
    // static_cast<X&>(b2);
    // dynamic_cast<X&>(b1);   // ok if the source type (Base) is polymorphic
    [[maybe_unused]] Derived &d1b = static_cast<Derived&>(x1);  // downcast from a non-virtual base is ok
}
