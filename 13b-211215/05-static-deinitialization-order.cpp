#include <vector>
#include <iostream>

std::vector<int> &some_vector();

struct VeryWeirdObject {
    ~VeryWeirdObject() {
        std::cout << some_vector().size() << "\n";  // May be uninitialized already, e.g. with clang++ and libc++
        some_vector().emplace_back(20);
    }
} object;

std::vector<int> &some_vector() {
    static std::vector<int> vec{1, 2, 3};
    return vec;

    // Better option: never deinitialize
    // https://isocpp.org/wiki/faq/ctors#construct-on-first-use-v2
    // static auto *vec = new std::vector<int>{1, 2, 3};
    // return *vec;
}

int main() {
    std::cout << some_vector().size() << "\n";
}
