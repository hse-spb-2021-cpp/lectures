#include <cassert>
#include <iostream>

void read_line(char **s) {
    *s = new char[10];  // Assume noexcept.
    // *s = new char[10]{};
    std::cin.read(*s, 9);  // Does not add zero terminator
    (*s)[std::cin.gcount()] = 0;
}

void read_line_buffered(char **s) {
    static char buffer[10];
    *s = buffer;
    std::cin.read(*s, 9);
    (*s)[std::cin.gcount()] = 0;
}

int main() {
    char *s = nullptr;
    read_line(&s);
    std::cout << s << "\n";
    delete[] s;

    read_line_buffered(&s);
    std::cout << s << "\n";
    // delete[] s;  // No need, it points to a buffer.

    // Moral: easy to confuse what to clean up and how. Used very rarely.
}
