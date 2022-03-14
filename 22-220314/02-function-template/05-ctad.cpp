#include <utility>

// C++17: class template argument deduction (CTAD)
template<typename TA, typename TB>
struct pair {
    TA a;
    TB b;

    pair() {}
    pair(TA a_, TB b_) : a(std::move(a_)), b(std::move(b_)) {}
};
// "Deduction guides" are generated from constructors by default: https://en.cppreference.com/w/cpp/language/class_template_argument_deduction
// template<typename TA, typename TB> pair(TA, TB) -> pair<TA, TB>;

template<typename TA, typename TB>
pair<TA, TB> make_pair(TA a_, TB b_) {
    return {std::move(a_), std::move(b_)};
}

int main() {
    [[maybe_unused]] auto p1 = pair(10, 20);
    [[maybe_unused]] pair p2(10, 20);
    [[maybe_unused]] pair<double, int> p3(10, 20);
    // [[maybe_unused]] pair<double> p4(10, 20);  // Either all arguments are specified, or full CTAD.

    // Work around + life before C++17: argument deduction for functions.
    [[maybe_unused]] auto p5 = make_pair<double>(10, 20);
}
