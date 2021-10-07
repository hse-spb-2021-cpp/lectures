// https://www.fluentcpp.com/2018/01/30/most-vexing-parse/
struct Bar {
    explicit Bar() {}
    explicit Bar(int) {}
};
struct Foo {
    explicit Foo(Bar) {}
};

int main() {
    int x = 10;
    Foo f(Bar(x));  // the most vexing parse: Foo f(Bar (*arg) ())
    // Foo f{Bar(x)};
    // Foo f(Bar{x});
    // Foo f((Bar(x)));
    f = f;
}
