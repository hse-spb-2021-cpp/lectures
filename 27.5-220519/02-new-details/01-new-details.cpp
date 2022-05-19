#include <iostream>

int main() {
    int *i;

    i = new int{};  // value-initialization
    std::cout << *i << "\n";  // 0
    delete i;

    i = new int();  // value-initialization
    std::cout << *i << "\n";  // 0
    delete i;

    i = new int;  // default-initialization: uninitialized
    std::cout << *i << "\n";  // UB
    delete i;

    // same for placement new.
}
