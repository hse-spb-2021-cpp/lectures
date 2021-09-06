int main() {
    int n = 5;
    for (int i = 0; i < n; i++) {
        std::cout << i << "\n";
    }
    for (int i = 0; i < static_cast<int>(a.size()) - 1; i++) {
        std::cout << i << "\n";
    }
    // std::cout << i << "\n";

    int j = 5;
    for (; j < 10; j += 2) {
        std::cout << j << "\n";
    }
}