#include <algorithm>

struct Base {
    Base() {
    }
};

struct Derived1 final : Base {
    int value = 123;
};

// struct SubDerived : Derived1 {};  // impossible

struct Derived2 final : Base {
    int value = 456;
};

int main() {
}
