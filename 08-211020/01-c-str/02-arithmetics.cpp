#include <iostream>

int main() {
    const char *s = "hello";  // array-to-pointer decay
    std::cout << s << "\n";  // hello
    std::cout << s + 2 << "\n";  // llo
    s++;
    std::cout << s << "\n";  // ello
    std::cout << s - 1 << "\n";  // hello

    // std::cout << s - 2 << "\n";  // UB
}
