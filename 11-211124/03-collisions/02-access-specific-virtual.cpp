#include <iostream>

struct Base {
    virtual void foo() {
        std::cout << "Base\n";
    }
};

struct Derived : Base {
    void foo() override {
        Base::foo();  // non-virtual call: Base
        std::cout << "Derived\n";
    }
};

int main() {
    Derived d;
    d.foo();        // virtual call: Base, Derived
    d.Base::foo();  // non-virtual call: Base

    std::cout << "=====\n";

    Base &b = d;
    b.foo();        // virtual call: Base, Derived
    b.Base::foo();  // non-virtual call: Base
}
