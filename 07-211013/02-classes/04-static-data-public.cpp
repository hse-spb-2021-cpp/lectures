#include <cassert>
#include <iostream>

struct Counter {
public:
    static int calls;  // Declaration.

    static int counter() {
        return ++calls;
    }
};

int Counter::calls = 0;  // Should be in exactly one TU (see ODR).
// float Counter::calls = 0;  // Conflict.

int main() {
    assert(Counter::counter() == 1);
    assert(Counter::counter() == 2);
    assert(Counter::counter() == 3);
    assert(Counter::counter() == 4);

    // [[maybe_unused]] int x = calls;  // no variable
    // counter();  // no function

    Counter c1, c2;

    assert(Counter::calls == 4);
    assert(c1.calls == 4);
    assert(c2.calls == 4);
    Counter::calls++;
    c1.calls++;
    assert(Counter::counter() == 7);
    assert(c1.calls == 7);
    assert(c2.calls == 7);
}
