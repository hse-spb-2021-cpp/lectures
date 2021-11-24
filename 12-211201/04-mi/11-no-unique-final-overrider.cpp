#include <iostream>
#include <cstddef>
// https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister

struct Base {
    int field = 100;
    virtual void foo() {};
    virtual void bar() {};
    virtual void baz() = 0;
};

struct Derived1 : virtual Base {
    void foo() override {
        bar();
    }
    void baz() override {
    }
};

struct Derived2 : virtual Base {
    void bar() override {
    }
//    void baz() override {  // No unique final overrider in DerivedX, так в принципе нельзя с множественным наследованием.
//    }
};

struct DerivedX : Derived1, Derived2 {
};

int main() {
    DerivedX a;
    a.foo();  // Derived1::foo() --> Base::bar() ~~ Derived2::bar()

    Derived1 b;
    b.foo();  // Derived1::foo() --> Base::bar()
}
