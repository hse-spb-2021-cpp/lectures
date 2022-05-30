#include <boost/hana.hpp>
#include <iostream>

template<typename Fn, typename ...Args>
auto is_valid(Fn fn, Args &&...args) -> decltype(fn(std::forward<Args>(args)...), bool()) {
    return true;
}

auto is_valid(...) -> bool {
    return false;
}

int main() {
    // We have to make each individual argument a valid expression to avoid hard error.
    // Hence, we should separate exact values from the expression.
    // The expression gets baked in a template, we then try to substitute arguments inside.
    std::cout << is_valid([](auto a, auto b) -> decltype(a + b, void()) {}, 10, 20) << "\n";  // 1
    std::cout << is_valid([](auto a, auto b) -> decltype(a + b, void()) {}, "x", "y") << "\n";  // 0

    auto checker = boost::hana::is_valid([](auto a, auto b) -> decltype(a + b, void()) {});
    std::cout << checker(10, 20) << "\n";  // 1
    std::cout << checker("x", "y") << "\n";  // 0
}
