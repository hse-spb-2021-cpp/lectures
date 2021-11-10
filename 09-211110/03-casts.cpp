#include <iostream>

struct Base {  // Базовый класс (base) в C++. Родительский/предок/надкласс/суперкласс (Python, Java).
    int x = 10;
    void foo() const {
        std::cout << "x=" << x << "\n";
    }
};

struct Derived : Base {  // Производный класс (derived). Дочерний/подкласс.
    int y = 20;
    void bar() const {
        foo();
        std::cout << "y=" << y << "\n";
    }
};

void foo(const Base &b) {
    std::cout << "foo(" << b.x << ")\n";
    const Derived &d = static_cast<const Derived&>(b);  // derivedcast (C++), downcast (others).
    std::cout << ".y=" << d.y << "\n";
}

void bar(Base b) {  // Slicing.
    std::cout << "bar(" << b.x << ")\n";
    const Derived &d = static_cast<const Derived&>(b);  // derivedcast, UB
    std::cout << ".y=" << d.y << "\n";  // UB
    &d.y;  // UB
}

int main() {
    {
        Derived d;
        foo(d);  // Not UB: d is really Derived.

        // Base(const Base &other) : x(other.x)
        bar(d);  // Always UB.
    }
    {
        Base b;
        foo(b);  // UB!
        bar(b);  // Always UB.
    }
}
