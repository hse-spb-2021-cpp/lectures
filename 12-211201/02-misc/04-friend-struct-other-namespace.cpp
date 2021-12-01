namespace ns2 {
struct Bar;
}

namespace ns1 {
struct Foo {
private:
    int x = 0;

    friend /*struct*/ ns2::Bar;  // struct is optional if 'ns2::Bar' exists.
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
