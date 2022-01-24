#include <iostream>
#include <vector>

int main() {
    try {
        std::vector<int> v(100'000'000'000);
        try {
            v[99'999'999'999] = 123;
        } catch (...) {
            std::cout << "caught exception not inside v ctor\n";
        }
    } catch (std::bad_alloc &) {
        std::cout << "caught bad_alloc inside v ctor\n";
    }
}
