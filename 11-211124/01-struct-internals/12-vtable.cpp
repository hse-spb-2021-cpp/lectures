#include <functional>
#include <iostream>
#include <vector>

struct Base;

struct BaseVtable {
    using print_impl_ptr = void(*)(Base*);
    print_impl_ptr print_ptr;
};

struct Base {
    static BaseVtable BASE_VTABLE;

    BaseVtable *vtable = &BASE_VTABLE;
    int x = 10;

    static void print_impl(Base *b) {
        std::cout << "x = " << b->x << "\n";
    }

    void print() {
        vtable->print_ptr(this);
    }
};
BaseVtable Base::BASE_VTABLE{Base::print_impl};

struct Derived : Base {
    static BaseVtable DERIVED_VTABLE;

    int y = 20;

    static void print_impl(Base *b) {
        Derived *d = static_cast<Derived*>(b);
        std::cout << "x = " << d->x << ", y = " << d->y << "\n";
    }

    Derived() {
        vtable = &DERIVED_VTABLE;
    }
};
BaseVtable Derived::DERIVED_VTABLE{Derived::print_impl};

int main() {
    Base b;
    Derived d;
    b.print();
    d.print();

    Base &db = d;
    db.print();

    std::cout << sizeof(Base) << ", " << sizeof(Derived) << "\n";
}
