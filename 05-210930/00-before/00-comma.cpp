#include <iostream>

int main() {
    int a = 0, b = 0, c = 0;
    a++, a += 1, b += 20, std::cout << a, b++, c++;  // expression, expression
    for (;;) {}  // statement

    for (int i = 0, j = 0, k = 0; i < 10; i++, j++, k++) {
        std::cout << i << j << k << "\n";
    }

    // X, Y: evaluate(X), evaluate(Y), return Y
    // X, Y: { X; return Y; }
}

// Can be overloaded, but be careful with short-circuit and order of evaluation:
// operator&&
// operator||
// operator,
