#include <iostream>

struct Base {
    int f = 10;
    void foo() {
        std::cout << "Base\n";
    }
};

struct Derived : Base {
    int f = 20;   // It 'hides' `f` from `Base`
    void foo() {  // It 'hides' `foo` from `Base`
        Base::foo();
        std::cout << "Derived " << f << " " << Base::f << "\n";
    }
};

int main() {
    Derived d;
    d.foo();

    // This syntax is for naming only, it does not alter access restrictions
    // (public/protected/private).
    d.Base::foo();
    std::cout << d.f << " " << d.Base::f << "\n";
}
