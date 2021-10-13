#include <string>
#include <iostream>

template<typename T>
struct Foo {};

using FooI = Foo<int>;
//using FooI = std::string;

struct bigint {
    bigint(FooI) {}
    operator FooI() { return {}; }
};

bool operator==(const bigint &, const bigint &) {
    return true;
}

template<typename T>
bool operator==(const Foo<T> &, const Foo<T> &) {
    return false;
}

int main() {
    bigint(FooI{}) == FooI{};
}
