#include <utility>

struct Base {
    Base() {
    }

protected:
    Base(const Base &) = default;
    Base(Base &&) = default;
    Base &operator=(const Base &) = default;
    Base &operator=(Base &&) = default;
};

struct Derived : Base {
    // All special methods are re-generated in each class and are public by
    // default. They need non-deleted and at least 'protected' parent methods.
};

int main() {
    [[maybe_unused]] Base b1, b2;
    // Base b3 = b1;
    // Base b4 = std::move(b1);
    // b1 = b2;
    // b1 = std::move(b2);

    Derived d1, d2;
    [[maybe_unused]] Derived d3 = d1;
    [[maybe_unused]] Derived d4 = std::move(d1);
    d1 = d2;
    d1 = std::move(d2);
}
