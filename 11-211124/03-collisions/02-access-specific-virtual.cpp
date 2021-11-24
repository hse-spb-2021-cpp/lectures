#include <iostream>

struct Base {
    virtual void foo() {
        std::cout << "Base\n";
    }
};

struct Derived : Base {};

struct SubDerived : Derived {
    void foo() override {
        Base::foo();     // non-virtual call: Base
        Derived::foo();  // non-virtual call: Derived --> Base
        std::cout << "Derived\n";
    }
};

int main() {
    SubDerived sd;
    sd.foo();           // virtual call: Base, Derived
    sd.Derived::foo();  // non-virtual call: Derived --> Base
    sd.Base::foo();     // non-virtual call: Base

    std::cout << "=====\n";

    Derived &d = sd;
    d.foo();           // virtual call: Base, Derived
    d.Derived::foo();  // non-virtual call: Derived --> Base
    d.Base::foo();     // non-virtual call: Base
    std::cout << "=====\n";

    Base &b = sd;
    b.foo();        // virtual call: Base, Derived
    b.Base::foo();  // non-virtual call: Base
}
