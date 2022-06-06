#include <vector>
#include <iostream>

struct Base {
    Base() {
        throw 0;
    }
};

struct Foo : Base {
    std::vector<int> a, b;

    Foo(const std::vector<int> &a_, const std::vector<int> &b_)
    try
        : a(a_)
        , b(b_)
    {
    } catch (const std::bad_alloc &) {
        // Catching exceptions from: member initialization list (even omittied), constructor's body.
        std::cout << "Allocation failed\n";
        // All fields and bases are already destroyed. The object may be destroyed as well (e.g. delegating ctor).
        // We do not know what exactly has failed.
        // No way to resurrect the object. `throw;` is added implicitly.
    } catch (int x) {
        std::cout << "Oops\n";
        // We can change the exception, though.
        throw 10;
    }
};

int main() {
    try {
        Foo f({}, {});
    } catch (int x) {
        std::cout << "exception " << x << "\n";
    }
}
