#include <iostream>
#include <utility>

struct Foo {
    Foo() {
        std::cout << "Foo(): " << this << "\n";
    }
    Foo(const Foo &other) {  // copy constructor
        std::cout << "Foo(const Foo &): " << this << " <- " << &other << "\n";
    }
    Foo &operator=(const Foo &other) {  // copy assignment operator
        std::cout << "operator=(const Foo &) " << this << " <- " << &other << "\n";
        return *this;
    }
    Foo(Foo &&other) {  // move constructor
        std::cout << "Foo(Foo &&) " << this << " <- " << &other << "\n";
    }
    Foo &operator=(Foo &&other) {  // move assignment operator
        std::cout << "operator=(Foo &&) " << this << " <- " << &other << "\n";
        return *this;
    }
    ~Foo() {
        std::cout << "~Foo(): " << this << "\n";
    }
};

void foo(Foo) {
}

Foo get_foo() {
    return {};
}

Foo get_foo_complex() {
    return {};
}

int main() {
    {
        std::cout << "===== Copy construction =====\n";
        Foo a;
        Foo b{a};
        Foo c = a;
        foo(a);
        Foo d = get_foo();  // Some optimizations are possible
    }
    {
        std::cout << "===== Copy assignment =====\n";
        Foo a;
        Foo b;
        b = a;
    }
    {
        std::cout << "===== Move construction =====\n";
        Foo a;
        Foo b{std::move(a)};
        Foo c = std::move(a);
        foo(std::move(a));
        Foo d = std::move(get_foo());  // Please do not add extra std::move, it's bad
    }
    {
        std::cout << "===== Move assignment =====\n";
        Foo a;
        Foo b;
        b = std::move(a);
    }
}
