#include <cstddef>
#include <utility>

// https://stackoverflow.com/a/3279550/767632

struct minivector {
private:
    int *data = nullptr;
    std::size_t len = 0;

public:
    minivector(std::size_t len_) : data(new int[len_]{}), len(len_) {}
    minivector(minivector &&other) : data(std::exchange(other.data, nullptr)), len(std::exchange(other.len, 0)) {}
    minivector(const minivector &other) : minivector(other.len) {
        for (std::size_t i = 0; i < len; i++) {
            data[i] = other.data[i];
        }
    }
    ~minivector() {
        delete[] data;
    }

    // swap is not needed if we have `operator=(minivector&&)`
    minivector &operator=(minivector &&other) {
        std::swap(data, other.data);
        std::swap(len, other.len);
        return *this;
    }
    minivector &operator=(const minivector &other) {
        if (this == &other) {  // Needed, otherwise we delete data.
            return *this;
        }
        if (len != other.len) {
#if 1  // incorrect
            delete[] data;
            // If it throws, we have UB. Workaround: `data = nullptr; len = 0;`
            data = new int[other.len];
#else  // correct
            int *new_data = new int[other.len];
            delete[] data;
            data = new_data;
#endi
        }
        for (std::size_t i = 0; i < other.len; i++) {
            data[i] = other.data[i];
        }
        return *this;
    }
};

int main() {
    minivector a(5), b(10);
    a = b;
}
