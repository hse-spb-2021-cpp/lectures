#include <iostream>

struct Base {
    virtual void foo() = 0;
};

struct Derived : Base {};

struct SubDerived : Derived {
    void foo() override {
        Base::foo();     // Linkage error.
        Derived::foo();  // Derived --> Base.
        std::cout << "Derived\n";
    }
};

int main() {
    SubDerived sd;
    sd.foo();
    sd.Base::foo();     // Linkage error.
    sd.Derived::foo();  // Derived --> Base

    // Base b;  // still abstract!
    // Derived d;  // still abstract!
}

void Base::foo() {
    // Can only be called via qualified name.
    std::cout << "Not really pure\n";
}
