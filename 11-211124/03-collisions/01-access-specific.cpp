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

struct SubDerived : Derived {};

int main() {
    SubDerived sd;
    sd.foo();
    std::cout << sd.Derived::f << "\n";
    std::cout << sd.SubDerived::f << "\n";  // Derived::f

    // This syntax is for naming only, it does not alter access restrictions
    // (public/protected/private).
    sd.Base::foo();
    std::cout << sd.f << " " << sd.Base::f << "\n";
}
