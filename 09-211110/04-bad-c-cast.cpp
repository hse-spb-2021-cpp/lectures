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

struct Foo {
    std::string s;
};

void foo(const Base &b) {
    std::cout << "foo(" << b.x << ")\n";
//    const Foo &d = static_cast<Foo&>(b);
    const Foo &d = (Foo&)(b);
    std::cout << ".s=" << d.s << "\n";
}

int main() {
    Derived d;
    foo(d);
}
