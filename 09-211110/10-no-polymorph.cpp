#include <iostream>
#include <vector>

struct Base {
    int x = 10;

    void print() const {
        std::cout << "x = " << x << "\n";
    }
};

struct Derived : Base {
    int y = 20;

    void print() const {
        std::cout << "y = " << y << "\n";
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
