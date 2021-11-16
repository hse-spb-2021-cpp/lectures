#include <boost/core/demangle.hpp>
#include <iostream>
#include <memory>
#include <typeinfo>

// RTTI is for polymorphic classes only.
struct Base {
    virtual ~Base() {
    }
};

struct Derived : Base {};

int foo() {
    std::cout << "foo()\n";
    return 10;
}

Derived &bar() {
    std::cout << "bar()\n";
    static Derived x;
    return x;
}

int main() {
    Base b;
    Derived d;

    // RTTI: Run-Time Type Information.
    // https://en.cppreference.com/w/cpp/language/typeid
    std::cout << "===== 1 (type) =====\n";
    const std::type_info &info_base = typeid(Base);
    const std::type_info &info_derived = typeid(Derived);
    const std::type_info &info_int = typeid(int);

    std::cout << boost::core::demangle(info_base.name()) << "\n";
    std::cout << boost::core::demangle(info_derived.name()) << "\n";
    std::cout << boost::core::demangle(info_int.name()) << "\n";

    std::cout << "===== 2b (non-polymorphic) =====\n";
    const std::type_info &info_int_expr =
        typeid(2 + 2 + foo());  // foo() is not called
    std::cout << boost::core::demangle(info_int_expr.name()) << "\n";

    std::cout << "===== 2a (polymorphic) =====\n";
    std::cout << boost::core::demangle(typeid(b).name()) << "\n";
    std::cout << boost::core::demangle(typeid(d).name()) << "\n";
    std::cout << boost::core::demangle(typeid(bar()).name())
              << "\n";  // bar() is called

    Base &bd = d;
    std::cout << boost::core::demangle(typeid(bd).name()) << "\n";

    std::unique_ptr<Base> dptr(new Derived);
    std::cout << boost::core::demangle(typeid(dptr).name()) << "\n";
    std::cout << boost::core::demangle(typeid(*dptr).name()) << "\n";
}
