#include <cassert>
#include <iostream>
#include <iterator>
#include <list>

struct Foo {
public:
    std::list<std::string> l;
    std::list<std::string>::iterator it;

public:
#if 1
    Foo()
       : l{"hello first very very very very long string", "hello second very very very very long string"}
       , it(std::next(l.begin())) {}
    void check() {
        assert(*it == "hello second very very very very long string");
    }
#else
    Foo() : l{"hello", "world"}, it(std::next(l.begin())) {}
    void check() {
        assert(*it == "world");
        assert(it == std::next(l.begin()));
    }
#endif
};

int main() {
    Foo a;
    std::cout << "checking a" << std::endl;
    a.check();

    {
        Foo b;
        std::cout << "checking b" << std::endl;
        b.check();

        a = b;
    }
    std::cout << "checking a" << std::endl;
    a.check();
}
