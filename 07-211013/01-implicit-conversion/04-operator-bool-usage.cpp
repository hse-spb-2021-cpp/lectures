#include <iostream>

int main() {
    [[maybe_unused]] int val;
    while (std::cin >> val) {}
    while ((std::cin >> val).operator bool()) {}

    // [[maybe_unused]] bool x1 = std::cin;
    [[maybe_unused]] bool x2 = static_cast<bool>(std::cin);

    // In C++03 and before: safe bool idiom
    // int x2 = 10 + std::cin;
}
