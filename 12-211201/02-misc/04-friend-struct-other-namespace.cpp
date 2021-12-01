namespace ns2 {
struct Bar;

struct Baz {
    struct Botva {
    };
};
}

namespace ns1 {
struct Foo {
private:
    int x = 0;

    friend /*struct*/ ns2::Bar;  // struct is optional if 'ns2::Bar' exists.
    // TODO: can we make a nested struct a friend? Yes we can. We cannot do cycles, though.
};
}

namespace ns2 {
struct Bar {
    void foo(ns1::Foo &f) {
        f.x++;
    }
    static void sfoo(ns1::Foo &f) {
        f.x++;
    }
};
}

int main() {
    ns1::Foo f;

    ns2::Bar b;
    b.foo(f);
    b.sfoo(f);
    ns2::Bar::sfoo(f);
}
