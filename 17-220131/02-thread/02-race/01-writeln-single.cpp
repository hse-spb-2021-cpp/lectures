#include <iostream>

void writeln(const char *s) {
    for (int i = 0; s[i]; i++) {
        std::cout << s[i];
    }
    std::cout << '\n';
}

int main() {
    for (;;) {
        writeln("Hello from the main thread");
    }
}
