#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;
void writeln(const char *s) {
    std::unique_lock{m};
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
