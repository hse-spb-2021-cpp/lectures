#include <utility>

struct Base {
    Base() {
    }

private:
    Base(const Base &) = default;
    Base(Base &&) = default;
    Base &operator=(const Base &) = default;
    Base &operator=(Base &&) = default;
};

struct Derived : Base {
    // All special methods are deleted.
};

int main() {
    Derived d1, d2;
    // [[maybe_unused]] Derived d3 = d1;
    // [[maybe_unused]] Derived d4 = std::move(d1);
    // d1 = d2;
    // d1 = std::move(d2);
}
