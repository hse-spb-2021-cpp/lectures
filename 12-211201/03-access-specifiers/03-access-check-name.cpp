struct Foo {
private:
    using MyType = int;
};

int main() {
    [[maybe_unused]] int x;  // ok
    [[maybe_unused]] Foo::MyType y;  // private, compilation error
}
