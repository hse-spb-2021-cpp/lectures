#include <cassert>
#include <type_traits>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };
struct Foo { int val = 0; };

template<typename T, typename U>
int operator+(const T &a, const U &b) {  // should only work for A, B, C, D, but not Foo
    return a.val + b.val;
}

int main() {
    A a{10};
    C c{30};
    [[maybe_unused]] Foo foo{50};
    assert(a + c == 40);  // should work
    assert(a + foo == 60);  // FIXME: should not compile
}
