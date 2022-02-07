#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;

// Приватный интерфейс.
void foo_lock_held(int x) {
    std::cout << "foo(" << x << ")\n";
}

// Публичный интерфейс из атомарных операций.
// Над ним надо очень хорошо думать, потому что комбинация двух атомарных операций неатомарна.
void foo(int x) {
    std::unique_lock l(m);
    foo_lock_held(x);
}

void double_foo(int x) {
    std::unique_lock l(m);
    foo_lock_held(x);
    foo_lock_held(x + 1);
}

int main() {
    const int N = 100'000;
    std::thread t([]() {
        for (int i = 0; i < N; i += 10)
            double_foo(i);
    });
    for (int i = 0; i < N; i += 10)
        foo(N + i);
    t.join();
}
