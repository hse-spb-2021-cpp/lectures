#include <iostream>
#include <thread>

void writeln(const char *s) {
    for (int i = 0; s[i]; i++) {
        std::cout << s[i];
    }
    std::cout << '\n';
}

int main() {
    std::thread t([]() {
        for (;;) {
            writeln("Hello from the second thread");
        }
    });
    for (;;) {
        writeln("Hello from the main thread");
    }
}
