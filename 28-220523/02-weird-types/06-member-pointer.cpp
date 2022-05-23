#include <cassert>
#include <functional>
#include <memory>

// https://isocpp.org/wiki/faq/pointers-to-members

struct S { int x = 1, y = 2; };
struct S2 : S { int z = 3; };

int main() {
    S s;
    S *sptr = &s;

    int S::*a = &S::x;  // ok
    int (S::*b) = &S::y;  // ok, unnecessary parens
    // int S::*с = &(S::y);  // compilation error: &S::y is a whole

    assert(s.*a == 1);
    assert(sptr->*a == 1);

    a = b;  // Now `a` "points" to a field `y` of arbitrary `S`.
    assert(s.*a == 2);
    assert(sptr->*a == 2);

    // void *wtf = (void*)a;  // invalid cast! It is not a pointer to memory, it is an offset

    // To simplify the syntax
    using IntMemberOfS = int S::*;
    [[maybe_unused]] IntMemberOfS c = &S::x;

    // Or a standard library
    std::invoke(a, s) = 3;
    assert(std::invoke(a, s) == 3);

    // Works with inheritance
    S2 s2;
    assert(s2.*a == 3);  // You can use pointer to a base member
    int S2::*d = a;  // There are implicit conversions
    assert(s2.*d == 3);
    [[maybe_unused]] IntMemberOfS e = static_cast<IntMemberOfS>(d);  // There are explicit conversions

    // Does not work with smart pointers (they forgot?)
    std::unique_ptr<S> p(new S);
    assert(std::invoke(a, *p) == 2);
    assert((*p).*a == 2);
    // assert(*p->*a == 2);  // compilation error, not overloaded
}
