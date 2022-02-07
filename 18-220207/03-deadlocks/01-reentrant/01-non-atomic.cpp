#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;

void foo(int x) {  // Атомарная операция, atomic.
    std::unique_lock l(m);
    std::cout << "foo(" << x << ")\n";
}

void double_foo(int x) {  // Неатомарная операция :(
    foo(x);
    foo(x + 1);
}

int main() {
    const int N = 100'000;
    std::thread t([]() {
        for (int i = 0; i < N; i += 10)
            double_foo(i);
    });
    for (int i = 0; i < N; i += 10)
        double_foo(N + i);
    t.join();
}
