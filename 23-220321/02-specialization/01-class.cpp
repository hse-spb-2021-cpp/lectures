#include <cassert>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>

template<typename T>
struct my_vector {
private:
    std::vector<T> data;
public:
    my_vector(int n) : data(n) {}
    T get(int i) { return data[i]; }
    void set(int i, T value) { data[i] = std::move(value); }
};

// my_vector<bool> v1(10);  // Implicit instantiation of my_vector<bool> before specialization is known, ODR violation

template<>
struct my_vector<bool>;  // Optional: specialization declaration, disables implicit instantiation.

template<>
struct my_vector<bool> {
private:
    std::vector<std::uint8_t> data;
public:
    my_vector(int n) : data((n + 7) / 8) {}
    bool get(int i) { return (data[i / 8] >> (i % 8)) & 1; }
    void set(int i, bool value) {
        if (value) {
            data[i / 8] |= 1 << (i % 8);
        } else {
            data[i / 8] &= ~(1 << (i % 8));
        }
    }
};

my_vector<bool> v2(10);

int main() {
    {
        my_vector<int> v(10);
        v.set(0, 100);
        v.set(8, 200);
        std::cout << v.get(0) << " " << v.get(1) << " " << v.get(8) << "\n";
    }
    {
        my_vector<bool> v(10);
        v.set(0, true);
        v.set(1, true);
        v.set(0, false);
        v.set(8, true);
        std::cout << v.get(0) << " " << v.get(1) << " " << v.get(8) << "\n";
    }
}
