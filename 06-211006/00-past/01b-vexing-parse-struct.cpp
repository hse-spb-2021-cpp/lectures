struct Bar {
    explicit Bar() {}
};
struct Foo {
    explicit Foo(Bar) {}
};

struct Botva {
    Foo f(Bar());
    // Foo f{Bar()};
    // Foo f(Bar{});
    // Foo f((Bar()));  // No :(
    // Foo f = Foo(Bar());  // Since C++17 no copy is guaranteed, before that it's very likely.

    // Foo f;
    // Botva() : f(Bar()) {}
};

int main() {
    Botva b;
    b.f = b.f;
}
