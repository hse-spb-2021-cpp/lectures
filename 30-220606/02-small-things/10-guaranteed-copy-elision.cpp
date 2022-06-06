#include <iostream>

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }

#if 1
    Foo(Foo &&other) {
        std::cout << "Foo(Foo&&) " << this << " <- " << &other << "\n";
    }

    Foo& operator=(Foo &&other) {
        std::cout << "operator=(Foo&&) " << this << " = " << &other << "\n";
        return *this;
    }
#else
    Foo(Foo &&other) = delete;
    Foo& operator=(Foo &&other) = delete;
#endif

    ~Foo() {
        std::cout << "~Foo() " << this << "\n";
    }
};

// (Almost) unique situation in C++: copy elision is allowed! Even if there are side effects of move/copy ctors.
Foo create_foo_rvo() {
    // Since C++17: guaranteed copy elision, no need in Foo(Foo&&)
    // Before C++17: needs Foo(Foo&&), even if never called
    return Foo();  // copy/move from prvalue is elided (RVO, return value optimization)
}

#if 1
Foo create_foo_nrvo() {
    Foo f;
    return f;  // NRVO (named return value optimization), not guaranteed
    // return std::move(f);  // prevents NRVO, no guaranteed copy elision as it's an xvalue
}

Foo create_foo_no_nrvo(int x) {
    Foo f, g;
    // probably no copy elision
    if (x == 0) {
        return f;
    } else {
        return g;
    }
}
#endif

void consume(Foo f) {
    std::cout << "consumed " << &f << "\n";
}

int main() {
    consume(create_foo_rvo());  // copy/move from prvalue is elided
#if 1
    std::cout << "=====\n";
    consume(create_foo_nrvo());  // copy/move from prvalue is elided
    std::cout << "=====\n";
    consume(create_foo_no_nrvo(0));
#endif
    // For constructors only, not assignment operators.
}
