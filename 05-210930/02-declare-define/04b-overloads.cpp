#include <iostream>

void foo(int);
// void foo(double);

int main() {
    foo(10.0);  // does not see foo(double), chooses foo(int)
}

void foo(int x) {
    std::cout << "int " << x << "\n";
}

void foo(double x) {
    std::cout << "double " << x << "\n";
}
