#include <cassert>
#include <iostream>

struct Counter {
private:
    static int calls;  // Declaration.

public:
    static int counter() {
        return ++calls;
    }

    static int get_calls() {  // no const-qualification possible
        return calls;
    }
};

int Counter::calls = 0;  // Should be in exactly one TU (see ODR).

int main() {
    assert(Counter::counter() == 1);
    assert(Counter::counter() == 2);
    assert(Counter::counter() == 3);
    assert(Counter::counter() == 4);

    Counter c1, c2;

    // [[maybe_unused]] int x1 = Counter::calls;  // private
    // [[maybe_unused]] int x2 = c1.calls;  // private
    // Counter::calls++;  // private
    // c1.calls++;  // private

    assert(Counter::get_calls() == 4);
    assert(c1.get_calls() == 4);
    assert(c2.get_calls() == 4);

    assert(Counter::counter() == 5);

    assert(Counter::get_calls() == 5);
    assert(c1.get_calls() == 5);
    assert(c2.get_calls() == 5);
}
