#include <utility>

struct Base {
    Base() {
    }

protected:
    Base(const Base &) = default;
    Base(Base &&) = default;
    Base &operator=(const Base &) = default;
    Base &operator=(Base &&) = default;

public:
    ~Base() = default;

    int field1;  // Should be copied/moved by 4 special functions.
};

class Derived : public Base {
    int field2;  // Should be copied/moved by 4 special functions => should generate them again, they call parent's to deal with field1.

    // All special methods are re-generated in each class and are public by
    // default (both for `struct` and `class`).
    // They need non-deleted and at least 'protected' parent methods.
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
