#include <functional>
#include <iostream>
#include <vector>

struct Base {
    int x = 10;

    void print() const {
        do_print();
    }

protected:
    std::function<void()> do_print = [&]() {
        std::cout << "x = " << x << "\n";
    };
};

struct Derived : Base {
    int y = 20;

    Derived() {
        do_print = [&]() {
            std::cout << "y = " << y << "\n";
        };
    }

    void print() const {
        do_print();
    }
};

int main() {
    Base b;
    Derived d;
    b.print();
    d.print();

    Base &db = d;
    db.print();

    std::cout << sizeof(Base) << ", " << sizeof(Derived) << "\n";
}
