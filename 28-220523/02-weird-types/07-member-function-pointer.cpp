#include <cassert>

struct S {
    int field = 100;
    int foo1(int x) { return x + 10 + field; }
    int foo2(int x) { return x + 20 + field; }
    int bar1(int x) const { return x + 30 + field; }
    int bar2(int x) const { return x + 40 + field; }
};

int main() {
    S s;
    int (S::*a)(int) = &S::foo1;
    assert((s.*a)(9) == 119);  // Parens are .* are necessary!
    a = &S::foo2;
    assert((s.*a)(8) == 128);
    assert(std::invoke(a, s, 7) == 127);

    // Be careful with const qualifiers: https://isocpp.org/wiki/faq/pointers-to-members#memfnptr-to-const-memfn
    int (S::*b)(int) const = &S::bar1;  
    assert((s.*b)(6) == 136);
    b = &S::bar2;
    assert((s.*b)(5) == 145);
    assert(std::invoke(b, s, 4) == 144);

    // ->* works as well

    // Works with virtual functions, virtual inheritance => may need multiple pointers and be big, incompatible with function pointers.
    // Be careful with overloads, just like in function pointers
}
