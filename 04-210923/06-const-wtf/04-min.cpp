#include <algorithm>
#include <iostream>

int main() {
    // Rvalue lifetime disaster, Arno Schoedl.
    const auto &val = std::min(3, 4);
    std::cout << val << "\n";
}
