#include <iostream>
#include <vector>

std::vector<int>& foo() {
    std::vector<int> vec{1, 2, 3};
    return vec;
}

int main() {
    std::vector<int> vec = foo();
    std::cout << vec.size() << "\n";
}
