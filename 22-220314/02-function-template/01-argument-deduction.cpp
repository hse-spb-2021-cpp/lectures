#include <vector>

// function template
template<typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T, typename U>
void foo(const std::vector<T> &, const std::vector<U> &) {
}

int main() {
    int x, y;
    [[maybe_unused]] short z;
    swap<int>(x, y);

    // template argument deduction
    swap(x, y);  // T = int
    // swap(x, z);  // compilation error: deduced conflicting types for T

    foo(std::vector<double>{}, std::vector<float>{});  // T=double, U=float
}
