#include <cassert>
#include <iostream>

struct Foo {
private:
    int x = 0;

    Foo() {}

public:
    static Foo create() {
        return Foo();
    }
    static void inc(Foo &f) {
        f.x++;
    }
    static int get(Foo &f) {
        return f.x;
    }
};

int main() {
    Foo f1 = Foo::create();
    Foo f2 = Foo::create();

    assert(Foo::get(f1) == 0);
    assert(Foo::get(f2) == 0);
    Foo::inc(f1);
    assert(Foo::get(f1) == 1);
    assert(Foo::get(f2) == 0);

    // Alternative syntax
    assert(f1.get(f1) == 1);
    assert(f1.get(f2) == 0);
    assert(f2.get(f1) == 1);
    assert(f2.get(f2) == 0);
}
