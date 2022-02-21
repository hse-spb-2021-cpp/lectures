#include <cstddef>
#include <mutex>
#include <vector>
#include <utility>

template<typename T>
struct atomic_vector {
private:
    mutable std::mutex m;
    std::vector<T> v;

public:
    void push_back(const T &x) {
        std::unique_lock l(m);
        v.push_back(x);
    }

    void push_back(T &&x) {
        std::unique_lock l(m);
        v.push_back(std::move(x));
    }

    const T &operator[](std::size_t i) const {
        std::unique_lock l(m);
        return v[i];
    }
};
