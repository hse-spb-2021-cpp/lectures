#include <iostream>

struct Base {  // Базовый класс (base) в C++. Родительский/предок/надкласс/суперкласс (Python, Java).
    int x = 10;
    void foo() const {
        std::cout << "x=" << x << "\n";
    }

private:
    int very_secret = 20;

protected:
    int secret = 30;
};

struct Derived : Base {  // Производный класс (derived). Дочерний/подкласс.
    int y = 30;
    void bar() const {
        foo();
        std::cout << "x=" << x << ", y=" << y << ", secret=" << secret << "\n";
        // int z = very_secret;
    }
};

int main() {
    {
        Derived d;
        std::cout << "d.x=" << d.x << ", d.y=" << d.y << "\n";
        d.foo();
        d.bar();
        // int x = d.very_secret;
        // int y = d.secret;
    }
    std::cout << sizeof(Base) << "," << sizeof(Derived) << "\n";
//    std::cout << sizeof(int*) << "\n";
}
