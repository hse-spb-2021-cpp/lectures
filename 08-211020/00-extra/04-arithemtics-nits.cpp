#include <cassert>
#include <functional>
#include <iostream>
#include <set>

struct Foo {
    int a = 10;
    int b = 20;
    int c = 30;
};

int main() {
    {
        int data[4];
        int end;
        std::cout << (&end - data) << "\n";  // ub
        std::cout << (data < &end) << "\n";  // ub
        assert(data != &end);  // ok
    }
    {
        Foo f;
        int *x = &f.a;
        assert(*x == 10);  // ok

        x++;  // not ub: one-past-end of a 'array of single element'
        std::cout << *x << "\n";  // ub, but may look reasonable, may be defined by compiler

        std::cout << &f.b - &f.a << "\n";  // ub: not an array
        assert(&f.a < &f.b);  // ok: members of the same access level (private/protected/public) are ordered
        assert(&f.a != &f.b);  // ok: different ints
    }
    {
        std::set<int*> s;
        int a = 10, b = 20;
        s.insert(&a);  // ok
        s.insert(&b);  // ok

        std::less<int*> comparator;
        std::cout << comparator(&a, &b) << "\n";  // implementation-defined
    }
}
