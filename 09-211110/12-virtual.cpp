#include <iostream>
#include <vector>

struct Base {
    int x = 10;

    virtual void print() const {
        std::cout << "x = " << x << "\n";
    }
    virtual void print2() const {
        std::cout << "x = " << x << "\n";
    }
    virtual void print3() const {
        std::cout << "x = " << x << "\n";
    }
    virtual void print4() const {
        std::cout << "x = " << x << "\n";
    }
    virtual void print5() const {
        std::cout << "x = " << x << "\n";
    }
    virtual void print6() const {
        std::cout << "x = " << x << "\n";
    }
};

struct Derived : Base {
    int y = 20;

    void print() const override /* C++11 */ {  // override: добавить virtual, проверить, что в родителе virtual есть.
                                               // На самом деле virtual добавляется автоматически, если был в родителе.
        std::cout << "x = " << x << ", y = " << y << "\n";
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
