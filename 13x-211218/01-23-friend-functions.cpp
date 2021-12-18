namespace ns {
struct Foo;
void foo(const Foo&);  // May be both before and after 'struct Foo'

struct Foo {
    friend void foo(const Foo&) {}
};
}

int main() {
    ns::Foo f;
    foo(f);
    ns::foo(f);
}
