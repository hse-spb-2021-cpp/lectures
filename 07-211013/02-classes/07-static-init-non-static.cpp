#include <cassert>
#include <iostream>

struct Counter {
private:
    static int calls;  // Declaration.
    int calls_on_creation = calls;

public:
    static int counter() {
        return ++calls;
    }

    static int get_calls() {  // no const-qualification possible
        return calls;
    }

    int get_calls_on_creation() const {
        return calls_on_creation;
    }
};

Counter c_global;

#if 0
int Counter::calls = 10;  // subtle: const initialization
#else
int Counter::calls = []() {  // subtle: dynamic initialization
    std::cout << "Counter::calls initialized\n";
    return 10;
}();
#endif

int main() {
    std::cout << c_global.get_calls_on_creation() << "\n";
    std::cout << Counter::get_calls() << "\n";
    // std::cout << Counter::get_calls_on_creation() << "\n";  // non-static method

    assert(Counter::counter() == 11);
    assert(Counter::counter() == 12);
    Counter c1;
    assert(Counter::counter() == 13);
    Counter c2;
    assert(Counter::counter() == 14);

    assert(c1.get_calls_on_creation() == 12);
    assert(c2.get_calls_on_creation() == 13);
}
