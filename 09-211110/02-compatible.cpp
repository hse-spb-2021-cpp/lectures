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

int main() {
    {
        Derived d;
        std::cout << "Via reference\n";
        Base &b = d;  // БЕСПЛАТНО! ТОЛЬКО СЕГОДНЯ^W^W ВСЕГДА
                      // basecast (C++), upcast (другие языки).
        b.foo();
        // b.bar();
        std::cout << "b.x=" << b.x << "\n";
        b.x++;
        std::cout << "d.x=" << d.x << "\n";
    }
    {
        Derived d;
        std::cout << "Via pointer\n";

        Derived *dptr = &d;
        Base *bptr = dptr;
        bptr->foo();
        // bptr->bar();
        std::cout << "b.x=" << bptr->x << "\n";
        bptr->x++;
        std::cout << "d.x=" << d.x << "\n";

        std::cout << dptr << " " << bptr << "\n";
        std::cout << &d.x << " " << &d.y << "\n";
    }
    std::cout << sizeof(Base) << " " << sizeof(Derived) << "\n";
}
