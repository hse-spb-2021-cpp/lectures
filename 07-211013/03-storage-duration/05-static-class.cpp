#include <cassert>
#include <iostream>

struct Counter {
private:
    static int calls;  // Declaration

    int calls_on_creation = calls;

public:
    static int counter() {
        return ++calls;
    }
};

int Counter::calls = 10;

int main() {
    assert(Counter::counter() == 11);
    assert(Counter::counter() == 12);
    assert(Counter::counter() == 13);
    assert(Counter::counter() == 14);
}
