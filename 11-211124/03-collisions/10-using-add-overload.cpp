#include <iostream>

// Order:
// 1. Name resolution. Output: "overload set".
// 2. Overload resolution. Output: a single overload.
// 3. Access check.
// 4. Call, can be virtual or non-virtual.

struct Base {
    void foo() {
        std::cout << "no args\n";
    }
    void foo(int) {
        std::cout << "int\n";
    }
};

struct Derived : Base {
    void foo(double) {
        std::cout << "double\n";
    }
    // void foo(int) { std::cout << "Derived int\n"; }  // Will hide, no
    // compilation error.

    // using Base::foo;  // Introduce members of Base called 'foo' into the
    // definition.
};

struct SubDerived : Derived {  // Has the same overloads as Derived
};

int main() {
    Base b;
    b.foo(1);    // int
    b.foo(1.2);  // int
    b.foo();     // no args

    Derived d;
    d.foo(1.2);  // double
    d.foo(1);    // double :(
    d.foo();     // compilation error?
    // Rule: if the derived class has a method called `foo`, do not look at
    //       base's methods, "hide" them.

    Base &d2 = d;
    d2.foo(1);    // int
    d2.foo(1.2);  // int
}
