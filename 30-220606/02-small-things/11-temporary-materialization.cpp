#include <iostream>

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }

    Foo(Foo &&other) {
        std::cout << "Foo(Foo&&) " << this << " <- " << &other << "\n";
    }

    Foo& operator=(Foo &&other) {
        std::cout << "operator=(Foo&&) " << this << " = " << &other << "\n";
        return *this;
    }

    ~Foo() {
        std::cout << "~Foo() " << this << "\n";
    }
};

Foo create_foo_rvo() {
    return Foo();  // copy/move from prvalue is elided (RVO, return value optimization)
}

Foo create_foo_nrvo() {
    Foo f;
    return f;  // NRVO (named return value optimization), not guaranteed
}

Foo &&pass_ref(Foo &&f) {  // Forces "temporary materialization" by binding a reference, now it's xvalue at best
    std::cout << "arg is " << &f << "\n";
    return std::move(f);
}

Foo pass_copy(Foo f) {  // Forces "temporary materialization" by binding a reference inside Foo(Foo&&)
    std::cout << "arg is " << &f << "\n";
    return f;  // no std::move to enable NRVO
}

void consume(Foo f) {
    std::cout << "consumed " << &f << "\n";
}

int main() {
    consume(pass_ref(create_foo_rvo()));
    std::cout << "=====\n";
    consume(pass_copy(create_foo_rvo()));
    std::cout << "=====\n";
    [[maybe_unused]] Foo f = Foo(Foo(Foo(Foo(Foo()))));
    std::cout << "=====\n";
    [[maybe_unused]] Foo g = Foo(Foo(Foo(static_cast<Foo&&>(Foo(Foo(Foo()))))));
}
