#include <iostream>

struct Base {
    int value = 123;

    virtual void foo() {
        std::cout << "foo(" << value << ")\n";
    };

    Base() {
        foo();
    }

    ~Base() {
        foo();
    }
};

struct Derived : Base {
    int value2 = 456;

    Derived() : Base(), value2(100) {
        foo();
    }

    void foo() override {
        std::cout << "foo(" << value << ", " << value2 << ")\n";
    }
};

int main() {
    Derived d;
    d.foo();
}
