#include <iostream>

struct Base {
    void foo() {
        std::cout << "Base\n";
    }
};

struct Derived : Base {
    virtual void foo() {
        std::cout << "Derived\n";
    }
    virtual ~Derived() {
    }
};

struct SubDerived : Derived {
    void foo() override {
        std::cout << "SubDerived\n";
    }
};

int main() {
    SubDerived sd;
    Derived &d = sd;
    Base &b = sd;

    sd.foo();  // SubDerived
    d.foo();  // SubDerived
    b.foo();  // Base

    sd.SubDerived::foo();  // SubDerived
    sd.Derived::foo();  // Derived
    sd.Base::foo();  // Base
}
