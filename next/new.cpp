#include <iostream>

int main() {
    int *i = new int;  // default-initialization: uninitialized
    delete i;
    i = new int{};  // value-initialization: 0
    delete i;

    int *ints = new int[5];  // default-initialization: uninitialized;
    std::cout << ints[0] << "\n";  // Technically UB, but may print 0 on lots of systems
    delete[] ints;

    ints = new int[5]{};  // value-initialization
    std::cout << ints[0] << "\n";
    delete[] ints;

    int x = 5;
    ints = new int[x]{1, 2};  // copy-initialization + value-initialization
                              // std::bad_array_new_length if x < 2
    std::cout << ints[0] << " " << ints[1] << " " << ints[2] << "\n";
    delete[] ints;
}