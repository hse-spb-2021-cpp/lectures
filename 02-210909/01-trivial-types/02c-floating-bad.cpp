#include <cmath>
#include <iostream>

// Ещё одно: https://codeforces.com/blog/entry/1059?locale=ru

int main() {
    int k = 5;
    std::cout << pow(10, k) << "\n";

    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= 10;
    }

    std::cout.precision(100);
    std::cout << log(100'000) / log(10) << "\n";
}
