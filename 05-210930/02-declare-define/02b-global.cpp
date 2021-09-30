#include <cassert>

struct Foo {
    int field;
};

int x;  // zero-initialization + default
Foo f;  // zero-initialization + default

int main() {
    assert(x == 0);
    assert(f.x == 0);
}
