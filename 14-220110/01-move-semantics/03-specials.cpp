#include <iostream>
#include <utility>

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }

    Foo(const Foo &other) {
        std::cout << "Foo(const Foo&) " << this << " <- " << &other << "\n";
    }

    Foo(Foo &&other) {
        std::cout << "Foo(Foo&&) " << this << " <- " << &other << "\n";
    }

    Foo& operator=(const Foo &other) {
        std::cout << "operator=(const Foo&) " << this << " = " << &other << "\n";
        return *this;
    }

    Foo& operator=(Foo &&other) {
        std::cout << "operator=(Foo&&) " << this << " = " << &other << "\n";
        return *this;
    }

    ~Foo() {
        std::cout << "~Foo() " << this << "\n";
    }
};

void call_by_value(Foo f) {
    std::cout << "call_by_value " << &f << "\n";
}

Foo create_foo() {
    Foo f;
    std::cout << "create_foo " << &f << "\n";
    return f;  // `f` is local variable => considered rvalue, please do not std::move it, details later.
}

int main() {
    Foo a;
    Foo b(/* lvalue */ a);
    Foo c(/* xvalue */ std::move(a));
    Foo d;

    b = /* lvalue */ d;
    b = /* xvalue */ std::move(d);

    // Copies/moves may be optimized out even if there are side effects, details are for later.
    std::cout << "===== call 1 =====\n";
    call_by_value(/* lvalue */ a);

    std::cout << "===== call 2 =====\n";
    call_by_value(/* xvalue */ std::move(a));

    std::cout << "===== call 3 =====\n";
    call_by_value(/* prvalue */ create_foo());

    std::cout << "===== dtors =====\n";
}
