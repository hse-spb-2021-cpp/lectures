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
    virtual ~Base() {}
};
struct X : virtual Base { int x_data = 0; };
struct Y : virtual Base { int y_data = 0; };
struct Derived : X, Y { };

int main() {
    Derived d1;
    X &x1 = d1;
    Base &b1 = d1;
    // d1: (baseptr x_data) (baseptr y_data) base_data

    X x2;
    Base &b2 = x2; // static_cast<Base&>(x2); is also ok
    // x2: (baseptr x_data) base_data

    std::cout << &x1 << " " << dynamic_cast<X*>(&b1) << "\n";
    std::cout << &x2 << " " << dynamic_cast<X*>(&b2) << "\n";
}
