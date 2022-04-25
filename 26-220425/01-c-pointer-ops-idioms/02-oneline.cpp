#include <iostream>

void strcpy(char *dst, const char *src) {
    while ((*dst++ = *src++));  // Double parens are to suppress warning.
}

// Look up: builtin vectorization functions

int main() {
    char src[] = "hello";
    char dst[10];
    strcpy(dst, src);
    std::cout << dst << "\n";
}
