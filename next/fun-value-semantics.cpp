#include <iostream>
#include <vector>

std::vector<int> concat(std::vector<int> a, std::vector<int> b) {
    for (int value : b) {
        a.emplace_back(value);
    }
    return a;
}

void println(std::vector<int> v) {
    bool first = true;
    for (int value : v) {
        if (!first) {
            std::cout << " ";
        }
        first = false;
        std::cout << value;
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> a{1, 2, 3};
    std::vector<int> b{4, 5, 6};
    auto ab{10, 10, 10};
    ab = concat(a, b);
    println(ab);
}
