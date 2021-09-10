#include <iostream>

int main() {
    int n = 239 << 4;
    std::cout << n << "\n";  // 239 * 2 ** 4
    std::cout << (n >> 4) << "\n";
}
