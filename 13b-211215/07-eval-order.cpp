// https://notes.algoprog.ru/cpp/additional.html#id4
// https://en.cppreference.com/w/cpp/language/eval_order
#include <iostream>
#include <vector>

int f(int x) {
    std::cout << "f(" << x << ")\n";
    return x;
}

int f(int x, int y) {
    std::cout << "f(" << x << ", " << y << ")\n";
    return x * 100 + y;
}

void f(int x, int y, int z) {
    std::cout << "f(" << x << ", " << y << ", " << z << ")\n";
}

std::vector<int> global_vec;
int foo() {
    global_vec.push_back(2);
    return 10;
}

int main() {
    f(f(1), f(2)); // f(1) and f(2) and indeterminitely sequenced

    std::cout << "=====\n";
    f(f(f(1), f(2)), f(3));  // Before C++17: any order, even f(1), f(3), f(2), f(1, 2). After C++17: no interleaving, f(3) is either the first or the last.

    std::cout << "=====\n";
    std::cout << f(1) << f(2) << "\n";  // Before C++17 any order. After C++17: f(1), 1, f(2), 2.

    std::cout << "=====\n";
    f(1), f(2);  // Left-to-right
    f(1) && f(2);  // Left-to-right + short-circuit
    f(0) && f(2);
    // Same for ||

    std::cout << "=====\n";
    global_vec.push_back(1);
    global_vec[0] = foo();  // Before C++17: any order, may induce UB. After C++17: right part, left part.
    std::cout << global_vec[0] << " " << global_vec[1] << "\n";

    std::cout << "===== pair()\n";
    [[maybe_unused]] std::pair<int, int> p1(f(1), f(2));  // Any order

    std::cout << "===== pair{}\n";
    [[maybe_unused]] std::pair<int, int> p2{f(1), f(2)};  // Left-to-right

    std::cout << "===== int a, b\n";
    [[maybe_unused]] int a = f(1), b = f(2);  // Left-to-right
}
