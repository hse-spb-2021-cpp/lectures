#include <cassert>
#include <iostream>

struct Counter {
private:
    static const int calls_init;
    static int calls;  // Declaration.

public:
    static int counter() {
        return ++calls;
    }

    static int get_calls() {  // no const-qualification possible
        return calls;
    }
};

const int Counter::calls_init = 10;  // subtle: const initialization
int Counter::calls = calls_init;  // we are "inside" Counter after ::
#if 0
// subtle: dynamic initialization
const int Counter::calls_init = []() {
    std::cout << "Counter::calls_init initialized\n";
    return 10;
}();
#endif

int main() {
    std::cout << Counter::get_calls() << "\n";
    assert(Counter::counter() == 11);
    assert(Counter::counter() == 12);
    assert(Counter::counter() == 13);
    assert(Counter::counter() == 14);
}
