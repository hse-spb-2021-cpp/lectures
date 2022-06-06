#include <cstddef>
#include <utility>

// https://stackoverflow.com/a/3279550/767632

struct minivector {
private:
    int *data = nullptr;
    std::size_t len = 0;

public:
    minivector(std::size_t len_) : data(new int[len_]{}), len(len_) {}
    // move is typically noexcept
    minivector(minivector &&other) noexcept : data(std::exchange(other.data, nullptr)), len(std::exchange(other.len, 0)) {}
    minivector(const minivector &other) : minivector(other.len) {
        for (std::size_t i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
    }
    ~minivector() {
        delete[] data;
    }

    // swap is typically noexcept and ADL-found
    friend void swap(minivector &a, minivector &b) noexcept {
        std::swap(a.data, b.data);
        std::swap(a.len, b.len);
    }
};

int main() {
    minivector a(5), b(10);
    swap(a, b);
}
