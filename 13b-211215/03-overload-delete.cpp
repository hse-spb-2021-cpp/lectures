#include <iostream>

// Since C++11:

void foo(int x) {
    std::cout << "foo(" << x << ")\n";
}
void foo(double) = delete;  // Last step: if chosen by overload resolution, fail compilation.

struct Bar {
    void foo(int x) {
        std::cout << "Bar::foo(" << x << ")\n";
    }
    void foo(double) = delete;
};

int main() {
    foo(10);
    foo(12.3);

    Bar b;
    b.foo(10);
    b.foo(12.3);
}
