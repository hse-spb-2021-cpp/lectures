#include <iostream>
#include <cstddef>
// https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister

struct Base {
    int field = 100;
    virtual void foo() {};
    virtual void bar() {};
};

struct Derived1 : virtual Base {
    void foo() override {
        bar();
    }
};

struct Derived2 : virtual Base {
    void bar() override {
    }
};

struct DerivedX : Derived1, Derived2 {
};

int main() {
    DerivedX a;
    a.foo();  // Derived1::foo() --> Base::bar() ~~ Derived2::bar()

    {
        Base &b = a;
        // Derived1 &d1 = static_cast<Derived1&>(b);  // impossible to static_cast during compile-time
        Derived1 &d1 = dynamic_cast<Derived1&>(b);
    }

    {
        Derived1 &d1 = a;
        // Derived2 &d2 = dynamic_cast<Derived2&>(static_cast<Base&>(d1));  // impossible to static_cast during compile time
        Derived2 &d2 = dynamic_cast<Derived2&>(d1);  // cross-cast
    }

    Derived1 b;
    b.foo();  // Derived1::foo() --> Base::bar()
}
