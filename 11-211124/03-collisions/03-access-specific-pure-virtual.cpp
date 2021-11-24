#include <iostream>

struct Base {
    virtual void foo() = 0;
};

struct Derived : Base {
    void foo() override {
        Base::foo();  // Linkage error.
        std::cout << "Derived\n";
    }
};

int main() {
    Derived d;
    d.foo();
    d.Base::foo();  // Linkage error.
}

void Base::foo() {
    // Can only be called via qualified name.
    std::cout << "Not really pure\n";
}
