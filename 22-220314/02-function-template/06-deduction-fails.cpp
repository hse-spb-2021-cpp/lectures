#include <vector>

template<typename T>
struct Base {
};

struct Derived1 : Base<int> {};
struct Derived2 : Base<double> {};
struct Derived3 : Base<int>, Base<double> {};

struct ConvertibleToBase {
    operator Base<int>() {
        return {};
    }
    // Even more fun for compiler and you
    // template<typename T> operator T() { return {}; }
    // https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Return_Type_Resolver
};

template<typename T>
void foo(const Base<T> &) {
}

int main() {
    foo(Base<int>());
    foo(Derived1());
    foo(Derived2());
    // foo(Derived3());  // compilation error: ambiguous base

    ConvertibleToBase x;
    [[maybe_unused]] const Base<int> &ref = x;
    // foo(x);  // compilation error: cannot deduce T because it won't go through all possible conversions
}
