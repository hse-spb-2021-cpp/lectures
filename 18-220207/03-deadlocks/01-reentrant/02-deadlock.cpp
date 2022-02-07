#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;

void foo(int x) {  // Атомарная операция, atomic.
    std::unique_lock l(m);
    std::cout << "foo(" << x << ")\n";
}

void double_foo(int x) {  // Неатомарная операция :(
    std::unique_lock l(m);  // Берём мьютекс первый раз.
    foo(x);  // Берём мьютекс второй раз, deadlock :( Можно было бы взять recursive_mutex, но это обычно плохой стиль.
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
