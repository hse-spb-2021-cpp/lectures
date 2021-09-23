#include <vector>

void print_vector([[maybe_unused]] const std::vector<int> &vec) {
}

int main() {
    [[maybe_unused]] std::vector<int> v1(10);
    [[maybe_unused]] std::vector<int> v2 = 10;
    print_vector(10);
}

