#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string *strs = new std::string[n];  // Array of 'n' std::string's,
    // Heap-allocated, dynamic storage duration.

    strs[0] = "hello world, this is the first string in the array";
    strs[1] = std::string(1000, 'x');
    for (int i = 0; i < n; i++) {
        std::cout << i << ": " << strs[i] << "\n";
    }
    delete[] strs;  // delete[], not just delete!

    // Inferior to std::vector, please never use.
}
