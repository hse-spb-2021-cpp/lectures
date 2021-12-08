#include <iostream>

struct Base {
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct X : virtual Base {
    void foo() override {
        std::cout << "X::foo()\n";
    }
};

struct Y : virtual Base {
    void foo() override {
        std::cout << "Y::foo()\n";
    }
    void bar() override {
        std::cout << "Y::bar()\n";
    }
};

struct Derived : X, Y {  // no unique final overrider for 'virtual void Base::foo()'
    /*void foo() override {
        std::cout << "Derived::foo()\n";
        X::foo();
        Y::foo();
    }*/
};

int main() {
}
