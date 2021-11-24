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

struct Derived;
struct DerivedVtable : BaseVtable {
    using mega_print_impl_ptr = void(*)(Derived*);
    mega_print_impl_ptr mega_print_ptr;
};

struct Derived : Base {
    static DerivedVtable DERIVED_VTABLE;

    int y = 20;

    static void print_impl(Base *b) {
        Derived *d = static_cast<Derived*>(b);
        std::cout << "x = " << d->x << ", y = " << d->y << "\n";
    }

    static void mega_print_impl(Derived *b) {
        std::cout << "megapring! y = " << b->y << "\n";
    }

    Derived() {
        vtable = &DERIVED_VTABLE;
    }

    void mega_print() {
        static_cast<DerivedVtable*>(vtable)->mega_print_ptr(this);
    }
};
DerivedVtable Derived::DERIVED_VTABLE{Derived::print_impl, Derived::mega_print_impl};

struct SubDerived : Derived {
    static DerivedVtable SUBDERIVED_VTABLE;

    int z = 20;

    static void mega_print_impl(Derived *b) {
        SubDerived *sd = static_cast<SubDerived*>(b);
        std::cout << "megapring! y = " << sd->y << ", z = " << sd->z << "\n";
    }

    SubDerived() {
        vtable = &SUBDERIVED_VTABLE;
    }
};
DerivedVtable SubDerived::SUBDERIVED_VTABLE{Derived::print_impl, SubDerived::mega_print_impl};

int main() {
    SubDerived sd;
    sd.print();
    sd.mega_print();

    Derived &d = sd;
    d.print();
    d.mega_print();

    Base &b = sd;
    b.print();
}
