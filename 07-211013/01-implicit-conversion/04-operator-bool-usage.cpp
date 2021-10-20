#include <iostream>

int main() {
    int val;
    while (std::cin >> val) {}
    /*
    .... operator>>(int &var) {
        var = ....
        return std::cin;
    }
    */

    while ((std::cin >> val).operator bool()) {}

    // bool x1 = std::cin;  // C++03: ok, C++11: not ok
    // int x2 = 10 + std::cin;  // Not ok in С++03 and C++11. How? operator bool() is implicit.
    // bool x3 = static_cast<bool>(std::cin);

    // In C++03 and before: safe bool idiom (extra reading).
    // In C++11 and after: explicit operator bool, see next example.
}
