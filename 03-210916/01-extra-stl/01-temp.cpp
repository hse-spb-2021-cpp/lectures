#include <utility>
#include <iostream>

void print_pair(std::pair<int, int> x) {
    std::cout << x.first << " " << x.second << "\n";
}

int main() {
    std::pair<int, int> x{10, 20};
    std::cout << x.first << " " << x.second << "\n";
    x.first = 239;
    std::cout << x.first << " " << x.second << "\n";

    print_pair({30, 40});
    print_pair(std::pair{30, 40});  // Class Template Argument Deduction (CTAD)
    print_pair(std::pair<int, int>{30, 40});

    // auto y = {100, 110.0};  // Useless, deduces either nothing or std::initializer_list
    // print_pair(y);

    [[maybe_unused]] std::pair<std::pair<int, double>,
              std::pair<float, int>> p2 = {{1, 2.0}, {3.0f, 4}};
    // Extra reading: brace elision
}
