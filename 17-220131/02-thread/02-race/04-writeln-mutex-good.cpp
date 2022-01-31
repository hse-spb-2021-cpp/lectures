#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;
void writeln(const char *s) {
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
            // std::this_thread::yield();  // Костыль!
        }
    });
    for (;;) {
        writeln("Hello from the main thread");
        // std::this_thread::yield();
    }
}
