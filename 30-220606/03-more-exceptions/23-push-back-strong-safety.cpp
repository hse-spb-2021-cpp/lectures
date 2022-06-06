#include <cstddef>
#include <utility>

// https://stackoverflow.com/a/3279550/767632

struct minivector {
private:
    int *data = nullptr;
    std::size_t len = 0;

public:
    minivector(std::size_t len_) : data(new int[len_]{}), len(len_) {}
    minivector(minivector &&other) noexcept : data(std::exchange(other.data, nullptr)), len(std::exchange(other.len, 0)) {}
    minivector(const minivector &other) : minivector(other.len) {
        for (std::size_t i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
    }
    ~minivector() {
        delete[] data;
    }

    minivector &operator=(minivector other) {
        std::swap(data, other.data);
        std::swap(len, other.len);
        return *this;
    }

    // Simple way to implement strong exception safety for all operations.
    // Probably with a performance penalty.
    void push_back(int x) {
        // Can throw, but `*this`'s state is unchanged.
        // Do everything in a temporary object.
        minivector other(len + 1);
        for (std::size_t i = 0; i < len; i++) {
            other.data[i] = data[i];
        }
        other.data[len] = x;
        // Now we have `other` in the correct state, let's swap.
        *this = std::move(other);
    }
};

int main() {
    minivector a(5), b(10);
    a = b;
}
