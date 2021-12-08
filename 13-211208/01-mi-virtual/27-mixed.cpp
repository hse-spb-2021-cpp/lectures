#include <iostream>

struct Base { int data; };
struct X : virtual Base {};
struct Y : virtual Base {};
struct Z : Base {};
struct Derived : X, Y, Z {};

int main() {
    Derived d;
    // d.data = 5;  // ambiguous
    // Base &b = d;  // ambiguous
    d.X::data = 10;
    d.Z::data = 20;

    std::cout << d.X::data << "\n";
    std::cout << d.Y::data << "\n";
    std::cout << d.Z::data << "\n";
}
