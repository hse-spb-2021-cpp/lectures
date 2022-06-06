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

    friend void swap(minivector &a, minivector &b) noexcept {
        std::swap(a.data, b.data);
        std::swap(a.len, b.len);
    }

    // copy-and-swap idiom is about making `operator=` strong exception safe AND simple
    minivector &operator=(minivector other) {  // copy or move to the temporary
        // swap with the temporary via our convenience method
        swap(*this, other);  // we can also write it in-place, but then std::swap will be inefficient
        // std::swap(*this, other);  // do not work, as it calls `operator=`
        return *this;
        // destroy the temporary
        // the only trouble: self-assignment is now not cheap
    }
};

int main() {
    minivector a(5), b(10);
    a = b;
}
