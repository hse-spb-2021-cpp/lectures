#include <cassert>
#include <iostream>

struct Counter {
private:
    static int call_start;
    static int calls;  // Declaration

    int calls_on_creation = calls;

public:
    static int public_x;

    static int counter() {
        return ++calls;
    }
};

Counter c;

int Counter::call_start = 0;  // Definition, in exactly one TU.
// float Counter::call_start = 0;  // Conflict

int Counter::calls = call_start;  // Initialized after 'call_start'
// int no_variable = calls;
// int no_access = Counter::calls;

int Counter::public_x = 10;
int has_access = Counter::public_x;

int counter() {
    return Counter::counter();
}

int main() {
    assert(counter() == 1);
    assert(counter() == 2);
    assert(counter() == 3);
    assert(counter() == 4);

    Counter c1, c2;
    std::cout << c1.public_x << "\n";
    c2.public_x++;
    std::cout << c1.public_x << "\n";
}
