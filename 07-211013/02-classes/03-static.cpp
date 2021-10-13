#include <cassert>

struct Foo {
private:
    // static member
    static inline int x = 10;
    int private_field;

public:
    static void foo() {
        x++;
    }
    static int get_x() {
        return x;
    }

    static void change_field(Foo &f) {
        f.private_field = 123;
    }

    // non-static member
    int y = 20;
    void bar() {
    }
};

int main() {
    Foo f;
    Foo::foo();
    assert(Foo::get_x() == 11);

    Foo::change_field(f);
}
