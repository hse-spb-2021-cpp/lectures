#include <iostream>
#include <type_traits>

template<typename T>
const T default_value{};

int main() {
    // complex_type<int>::some_const
    [[maybe_unused]] auto x = default_value<int>;
    [[maybe_unused]] auto y = default_value<double>;

    // Useful in metaprogramming: function of types/compile consts.
    std::cout << std::is_trivially_copyable_v<int> << std::endl;
    std::cout << std::is_trivially_copyable_v<std::istream> << std::endl;
}
