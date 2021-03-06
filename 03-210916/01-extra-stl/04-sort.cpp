#define _GLIBCXX_DEBUG
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 30, 2, 10, 3, 20, 4, 5};
    //            0   1  2   3  4   5  6  7
    std::sort(v.begin() + 2, v.end() - 1);

    for (int x : v) std::cout << " " << x;
    std::cout << "\n";

    std::sort(v.begin(), v.end(), [](int a, int b) {
        // operator<
        return std::abs(a - 7) < std::abs(b - 7);
//        return false;  // Ok: all elements are equal
//        return true;  // UB: irreflexivity is violated
    });

    for (int x : v) std::cout << " " << x;
    std::cout << "\n";
}
