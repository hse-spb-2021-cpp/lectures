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
    Derived() {
    }

protected:  // or private
    Derived(const Derived &) = default;
    Derived(Derived &&) = default;
    Derived &operator=(const Derived &) = default;
    Derived &operator=(Derived &&) = default;

    void foo() {
        Derived d1, d2;
        [[maybe_unused]] Derived d3 = d1;
        [[maybe_unused]] Derived d4 = std::move(d1);
        d1 = d2;
        d1 = std::move(d2);
    }
};

int main() {
    [[maybe_unused]] Base b1, b2;
    // Base b3 = b1;
    // Base b4 = std::move(b1);
    // b1 = b2;
    // b1 = std::move(b2);

    [[maybe_unused]] Derived d1, d2;
    // [[maybe_unused]] Derived d3 = d1;
    // [[maybe_unused]] Derived d4 = std::move(d1);
    // d1 = d2;
    // d1 = std::move(d2);
}
