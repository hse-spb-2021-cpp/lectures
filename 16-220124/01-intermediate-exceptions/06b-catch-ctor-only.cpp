#include <vector>
#include <iostream>

void foo(const std::vector<int> &v1) {
    std::vector<int> v2(v1.size() * 100'000);
    v2[v2.size() - 1] = 123;
}

int main() {
    try {
        std::vector<int> v1(1'000'000);
        foo(v1);  // We will also catch all exceptions from foo()!
    } catch (std::bad_alloc &) {
        std::cout << "caught bad_alloc from v1 or foo()\n";
    }

    // Theoretically possible:
    struct already_handled {};
    try {
        auto v1 = []() {
            try {
                return std::vector<int>(1'000'000);
                // return std::vector<int>(100'000'000'000);
            } catch (std::bad_alloc &) {
                std::cout << "caught bad_alloc from v1\n";
                throw already_handled();
            };
        }();
        foo(v1);  // now exceptions from foo() are not caught.
    } catch (already_handled &) {
        // do nothing, already handled.
    }
}
