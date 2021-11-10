#include <iostream>
#include <vector>

struct Base {
    int x = 10;

    virtual void print() const {
        std::cout << "x = " << x << "\n";
    }
};

struct Derived : Base {
    int y = 20;

    void print() const override /* C++11 */ {  // override: добавить virtual, проверить, что в родителе virtual есть.
                                               // На самом деле virtual добавляется автоматически, если был в родителе.
        std::cout << "y = " << y << "\n";
    }
};

int main() {
    std::cout << sizeof(Base) << "\n";

    Base b;
    Derived d;
    b.print();
    d.print();

    Base &db = d;
    db.print();

    std::cout << sizeof(Base) << ", " << sizeof(Derived) << "\n";
}
