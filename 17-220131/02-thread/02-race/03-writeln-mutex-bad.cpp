#include <iostream>
#include <mutex>
#include <thread>

void writeln(const char *s) {
    std::mutex m;
    m.lock();
    for (int i = 0; s[i]; i++) {
        std::cout << s[i];
    }
    std::cout << '\n';
    m.unlock();
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
